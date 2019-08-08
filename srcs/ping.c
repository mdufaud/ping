/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

static void				forge_icmp(t_env *env, struct icmp *icmp)
{
	icmp->icmp_type = ICMP_ECHO;
	icmp->icmp_code = ICMP_ECHOREPLY;
	icmp->icmp_id = env->pid;
	icmp->icmp_seq = env->icmp_req;
	icmp->icmp_cksum = 0;
}

static int				forge_packet(t_env *env, struct icmp *icmp)
{
	forge_icmp(env, icmp);
	env->packet_size = ICMP_MINLEN + 56;
	gettimeofday((struct timeval *)icmp->icmp_data, NULL);
	icmp->icmp_cksum = in_cksum((unsigned short *)icmp, env->packet_size);
	return (env->packet_size);
}

static void				set_struct(t_env *env)
{
	char			*s;

	s = NULL;
	env->icmp_req = 1;
	env->pid = getpid();
	env->end = 1;
	env->stat.n_recv = 0;
	env->stat.n_sent = 0;
	env->stat.min = 0;
	env->stat.max = 0;
	env->stat.sum = 0;
	env->stat.sum2 = 0;
	env->send_limit = 0;
	env->interval = 1;
	env->ttl = 64;
	if (env->arg->check(env->arg, "-c"))
	{
		s = env->arg->fetch(env->arg, "-c");
		if (s && ft_strisdigit(s))
			env->send_limit = ft_atoi(s);
		else
		{
			printf("ft_ping: bad number of packets to transmit.\n");
			exit(1);
		}
		free(s);
	}
	if (env->arg->check(env->arg, "-i"))
	{
		s = env->arg->fetch(env->arg, "-i");
		if (s && ft_strisdigit(s))
		{
			if ((env->interval = ft_atoi(s)) < 1)
			{
				printf("ft_ping: bad timing interval.\n");
				exit(1);
			}
		}
		else
		{
			printf("ft_ping: bad timing interval.\n");
			exit(1);
		}
		free(s);
	}
	if (env->arg->check(env->arg, "-t"))
	{
		s = env->arg->fetch(env->arg, "-t");
		if (s && ft_strisdigit(s))
		{
			if ((env->ttl = ft_atoi(s)) < 1)
			{
				printf("ft_ping: bad time-to-live value.\n");
				exit(1);
			}
		}
		else
		{
			printf("ft_ping: bad time-to-live value.\n");
			exit(1);
		}
		free(s);
	}
}

int						ping(t_env *env)
{
	struct icmp		icmp;

	if (env->send_limit && env->stat.n_sent == env->send_limit)
		return (0);
	if (forge_packet(env, &icmp) < 0)
		return (error("Error forging packet"));
	if (send_ip(env, &icmp) <= 0)
	{
		error("Invalid argument");
		exit(1);
	}
	env->icmp_req++;
	env->stat.n_sent++;
	return (0);
}

int						set_ping(t_env *env)
{
	struct icmp			s_icmp;
	int					ret;

	set_struct(env);
	env->s_icmp = &s_icmp;
	gettimeofday(&env->stat.start_time, NULL);
	if ((env->socket = socket(env->family, SOCK_RAW, env->family == AF_INET ? IPPROTO_ICMP : IPPROTO_ICMPV6)) == -1)
		return (error("Socket error"));
	if ((setsockopt(env->socket, IPPROTO_IP, IP_TTL, &env->ttl, sizeof(env->ttl))) == -1)
		return (error("Setting socket opt"));
	printf("PING %s (%s): 56(84) bytes of data.\n", env->host, env->addr);
	signal(SIGALRM, handler);
	signal(SIGINT, handler);
	if (env->arg->check(env->arg, "-A"))
		ping(env);
	else
		alarm(env->interval);
	while (env->end)
	{
		ret = recv_reply(env);
		if (env->send_limit && env->stat.n_recv == env->send_limit)
			print_stats();
		if (ret == -2 && env->arg->check(env->arg, "-A"))
		{
			while (ping(env))
				;
		}
	}
	close(env->socket);
	return (0);
}
