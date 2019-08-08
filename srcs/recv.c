/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

static int				set_reply(t_env *env, struct msghdr *msg, struct iovec *iov)
{
	char	*iov_data;
	char	msg_data[MSG_DATA_LEN];

	if (!(iov_data = ft_strnew(IOV_DATA_LEN)))
		return (error("Could not allocate data for iovec struct"));
	msg->msg_name = env->family == AF_INET ? (void *)&env->addr_in : (void *)&env->addr_in6;
	msg->msg_namelen = env->family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
	iov->iov_base = iov_data;
	iov->iov_len = IOV_DATA_LEN;
	msg->msg_iov = iov;
	msg->msg_iovlen = 1;
	msg->msg_control = msg_data;
	msg->msg_controllen = MSG_DATA_LEN;
	msg->msg_flags = 0;
	return (0);
}

static void				print_rtt(long triptime)
{
	if (triptime >= 100000)
		printf("%ld ms", triptime / 1000);
	else if (triptime >= 10000)
		printf("%ld.%01ld ms", triptime / 1000, (triptime % 1000) / 100);
	else if (triptime >= 1000)
		printf("%ld.%02ld ms", triptime / 1000, (triptime % 1000) / 10);
	else
		printf("%ld.%03ld ms", triptime / 1000, triptime % 1000);
}

static void				print_icmp_type_error(struct icmp *icmp)
{
	if (icmp->icmp_type == ICMP_TIME_EXCEEDED)
	{
		if (icmp->icmp_code == ICMP_EXC_TTL)
			printf("Time to live exceeded in transit ");
		else if (icmp->icmp_code == ICMP_EXC_FRAGTIME)
			printf("Fragment Reassembly Time Exceeded ");
		else
			printf("Code unknown ");
	}
	else if (icmp->icmp_type == ICMP_DEST_UNREACH)
	{
		if (icmp->icmp_code == ICMP_NET_UNREACH)
			printf("Network unreachable ");
		else if (icmp->icmp_code == ICMP_HOST_UNREACH)
			printf("Host unreachable ");
		else if (icmp->icmp_code == ICMP_PROT_UNREACH)
			printf("Protocol unreachable ");
		else if (icmp->icmp_code == ICMP_PORT_UNREACH)
			printf("Port unreachable");
		else if (icmp->icmp_code == ICMP_FRAG_NEEDED)
			printf("Fragmentation Needed/DF set ");
		else if (icmp->icmp_code == ICMP_SR_FAILED)
			printf("Source route failed ");
		else if (icmp->icmp_code == ICMP_PKT_FILTERED)
			printf("ICMP packet filtered ");
		else if (icmp->icmp_code == ICMP_NET_UNKNOWN)
			printf("Network unknown ");
		else if (icmp->icmp_code == ICMP_HOST_UNKNOWN)
			printf("Host unknown ");
		else
			printf("Code unknown ");
	}
	else if (icmp->icmp_type == ICMP_REDIRECT)
	{
		if (icmp->icmp_code == ICMP_REDIR_NET)
			printf("Redirect Net ");
		else if (icmp->icmp_code == ICMP_REDIR_HOST)
			printf("Redirect Host ");
		else if (icmp->icmp_code == ICMP_REDIR_NETTOS)
			printf("Redirect Net for TOS ");
		else if (icmp->icmp_code == ICMP_REDIR_HOSTTOS)
			printf("Redirect Host for TOS ");
		else
			printf("Code unknown ");
	}
	else if (icmp->icmp_type == ICMP_PARAMETERPROB)
	{
		printf("Parameter problem: ");
		if (icmp->icmp_code == 0)
			printf("pointer indicated the error ");
		else if (icmp->icmp_code == 1)
			printf("missing a required option ");
		else if (icmp->icmp_code == 2)
			printf("bad length ");
		else
			printf("code unknown ");
	}
	else
		printf("Type not found ");
}

static int				print_reply(t_env *env, char *s, int count)
{
	char			buf[BUFF_SIZE];
	struct ip		*ip;
	struct ip		*higher_ip;
	int				iphdr_len;
	struct icmp		*icmp;
	struct icmp		*higher_icmp;
	struct timeval	*time;
	struct timeval	*new;
	long			triptime;
	char			a;
	int				new_line;

	new_line = 1;
	ft_bzero(buf, BUFF_SIZE);
	a = 0x07;
	ip = (struct ip *)s;
	iphdr_len = ip->ip_hl << 2;
	icmp = (struct icmp *)(s + iphdr_len);
	higher_icmp = icmp;
	higher_ip = ip;
	count -= iphdr_len;
	if (count < 8)
	{
		printf("Packet too small\n");
		return (1);
	}
	if (icmp->icmp_type != ICMP_ECHOREPLY)
	{
		ip = &icmp->icmp_ip;
		iphdr_len = ip->ip_hl << 2;
		icmp = (struct icmp *)((char *)ip + iphdr_len);
	}
	else
		env->stat.n_recv++;
	time = (struct timeval *)higher_icmp->icmp_data;
	new = (struct timeval *)malloc(sizeof(struct timeval));
	ft_bzero(new, sizeof(struct timeval));
	gettimeofday(new, NULL);
	if ((new->tv_usec -= time->tv_usec) < 0)
	{       
		--new->tv_sec;
		new->tv_usec += 1000000;
	}
	new->tv_sec -= time->tv_sec;
	triptime = new->tv_sec * 1000000 + new->tv_usec;
	if (!env->arg->check(env->arg, "-q"))
	{
		if (!env->exact_host)
			printf("%d bytes from %s (%s): icmp_seq=%d ",
			count,
			env->host,
			inet_ntop(AF_INET, &higher_ip->ip_src, buf, BUFF_SIZE),
			icmp->icmp_seq);
		else
			printf("%d bytes from %s: icmp_seq=%d ",
			count,
			inet_ntop(AF_INET, &higher_ip->ip_src, buf, BUFF_SIZE),
			icmp->icmp_seq);
		if (higher_icmp->icmp_type == ICMP_ECHOREPLY)
		{
			printf("ttl=%d time=", higher_ip->ip_ttl);
			print_rtt(triptime);
		}
		else
		{
			print_icmp_type_error(higher_icmp);
			if (env->arg->check(env->arg, "-v"))
			{
				new_line = 0;
				printf("(type:%d, code:%d)\n", higher_icmp->icmp_type, higher_icmp->icmp_code);
			}
		}
	}
	if (!env->arg->check(env->arg, "-q") && new_line)
		printf("\n");
	if (env->arg->check(env->arg, "-a"))
		write(1, &a, 1);
	env->stat.min = (!env->stat.min || env->stat.min > triptime) ? triptime : env->stat.min;
	env->stat.max = (env->stat.max > triptime) ? env->stat.max : triptime;
	env->stat.sum += triptime;
	env->stat.sum2 += (long long)triptime * (long long)triptime;
	gettimeofday(&(env->stat.trip_time), NULL);
	free(new);
	free(s);
	return (-2);
}

static int				check_mine(t_env *env, struct icmp *icmp)
{
	struct ip	*ip;
	struct icmp	*tmp;
	int			iphdr_len;

	ip = &icmp->icmp_ip;
	iphdr_len = ip->ip_hl << 2;
	tmp = (struct icmp *)((char *)ip + iphdr_len);
	if (icmp->icmp_id == env->pid)
		return (1);
	if (tmp->icmp_id == env->pid)
		return (1);
	return (0);
}

int						recv_reply(t_env *env)
{
	struct msghdr		msg;
	struct iovec		iov;
	int					ret;
	struct ip			*ip;
	int					iphdr_len;
	struct icmp			*icmp;
	
	ft_bzero(&msg, sizeof(msg));
	ft_bzero(&iov, sizeof(iov));
	if ((set_reply(env, &msg, &iov)))
		return (-1);
	ft_bzero(iov.iov_base, 1024);
	ret = recvmsg(env->socket, &msg, MSG_DONTWAIT);
	if (ret > 0)
	{
		ip = (struct ip *)iov.iov_base;
		iphdr_len = ip->ip_hl << 2;
		icmp = (struct icmp *)(iov.iov_base + iphdr_len);
		if (ip->ip_p == IPPROTO_ICMP
			&& icmp->icmp_type != ICMP_ECHO)
		{
			if (check_mine(env, icmp))
				return (print_reply(env, iov.iov_base, ret));
		}
	}
	free(iov.iov_base);
	return (ret);
}
