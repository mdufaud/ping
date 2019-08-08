/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:19:44 by mdufaud           #+#    #+#             */
/*   Updated: 2016/02/16 19:12:34 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PING_H
# define PING_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>/////
# include <netdb.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <netinet/ip_icmp.h>

# define IOV_DATA_LEN 1024
# define MSG_DATA_LEN 4096
# define BUFF_SIZE 4096

typedef struct			s_ip_stat
{
	int					n_recv;
	int					n_sent;
	long				min;
	long				max;
	long long			sum;
	long long			sum2;
	struct timeval		start_time;
	struct timeval		trip_time;
}						t_ip_stat;

typedef struct			s_env
{
	t_arg				*arg;
	int					pid;
	int					icmp_req;
	int					socket;
	int					family;
	int					inet;
	int					packet_size;
	int					end;
	int					send_limit;
	int					exact_host;
	int					interval;
	int					ttl;
	char				*host;
	char				*addr;
	char				*canonname;
	char				*addr6;
	char				*canonname6;
	struct sockaddr_in	addr_in;
	struct sockaddr_in6	addr_in6;
	struct icmp			*s_icmp;
	struct s_ip_stat	stat;
}						t_env;

void					print_stats(void);
t_env					*get_env(t_env *env);
void					handler(int sig);
int						init_connect(t_env *env);
int						set_ping(t_env *env);
int						ping(t_env *env);
int						error(char *s);
int						error_j(char *err, char *s);
unsigned short			in_cksum(unsigned short *addr, int len);
int						recv_reply(t_env *env);
int						send_ip(t_env *env, struct icmp *imcp);

#endif
