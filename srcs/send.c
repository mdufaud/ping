/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

static int				send_ipv6(t_env *env, struct icmp *icmp)
{
	//REPLACE WIH ENV ADDR IN6
	struct sockaddr_in6	addr_in6;
	int					sent;

	addr_in6.sin6_family = AF_INET6;
	inet_pton(AF_INET6, env->addr6, &addr_in6.sin6_addr);
	sent = sendto(env->socket, icmp, env->packet_size, 0, (struct sockaddr *)&addr_in6, sizeof(struct sockaddr));
	//printf("Sent6 %d of %d bytes packet to %s\n", sent, env->packet_size, env->addr6);
	return (sent);
}

static int				send_ipv4(t_env *env, struct icmp *icmp)
{
	//REPLACE WIH ENV ADDR IN
	struct sockaddr_in	addr_in;
	int					sent;

	addr_in.sin_family = AF_INET;
	inet_pton(AF_INET, env->addr, &addr_in.sin_addr);
	sent = sendto(env->socket, icmp, env->packet_size, 0, (struct sockaddr *)&addr_in, sizeof(struct sockaddr));
	//printf("Sent4 %d of %d bytes packet to %s\n", sent, env->packet_size, env->addr);
	return (sent);
}

int						send_ip(t_env *env, struct icmp *icmp)
{
	if (env->family == AF_INET)
		return (send_ipv4(env, icmp));
	else if (env->family == AF_INET6)
		return (send_ipv6(env, icmp));
	return (-1);
}
