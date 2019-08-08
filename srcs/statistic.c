/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

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

static long	ft_llsqrt(unsigned long long a)
{
	long long	prev;
	long long	x;
	
	prev = ~((unsigned long long) 1 << 63);
	x = a;
	if (x > 0)
	{
		while (x < prev)
		{
			prev = x;
			x = (x + (a / x)) / 2;
		}
	}
	return ((long)x);
}

void		print_stats(void)
{
	t_env				*env;
	struct timeval		*new;
	long				triptime;
	long long			dev;
	float				loss;

	if (!(env = get_env(NULL)))
		return ;
	env->end = 0;
	new = (struct timeval *)malloc(sizeof(struct timeval));
	ft_bzero(new, sizeof(struct timeval));
	gettimeofday(new, NULL);
	if ((new->tv_usec -= env->stat.start_time.tv_usec) < 0)
	{       
		--new->tv_sec;
		new->tv_usec += 1000000;
	}
	new->tv_sec -= env->stat.start_time.tv_sec;
	triptime = new->tv_sec * 1000000 + new->tv_usec;
	printf("\n--- %s ft_ping statistics ---\n", env->host);
	loss = env->stat.n_sent == 0 ? 0 : ((float)((float)(env->stat.n_sent - env->stat.n_recv) / (float)env->stat.n_sent) * 100);
	printf("%d packets transmitted, %d received, ", env->stat.n_sent, env->stat.n_recv);
	if (env->stat.n_sent != env->stat.n_recv)
		printf("%d errors, ", (env->stat.n_sent) - (env->stat.n_recv));
	printf("%.0f%% packet loss, time ", loss);
	print_rtt(triptime);
	if (env->stat.n_recv >= 1)
	{
		env->stat.sum /= env->stat.n_recv;
		env->stat.sum2 /= env->stat.n_recv;
		dev = ft_llsqrt(env->stat.sum2 - env->stat.sum * env->stat.sum);
		printf("\nrtt min/avg/max/mdev = %ld.%03ld/%lu.%03ld/%ld.%03ld/%ld.%03ld ms",
		(long)env->stat.min / 1000,
		(long)env->stat.min % 1000,
		(unsigned long)(env->stat.sum / 1000),
		(long)(env->stat.sum % 1000),
		(long)env->stat.max / 1000,
		(long)env->stat.max % 1000,
		(long)dev / 1000,
		(long)dev % 1000);
	}
	printf("\n");
	free(new);
}
