/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_cksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

unsigned short	in_cksum(unsigned short *addr, int len)
{
	register int		sum;
	u_short				answer;
	register u_short	*w;
	register int		nleft;

	sum = 0;
	answer = 0;
	w = addr;
	nleft = len;
	while (nleft > 1)
	{
	  sum += *w++;
	  nleft -= 2;
	}
	if (nleft == 1)
	{
	  *(u_char *) (&answer) = *(u_char *) w;
	  sum += answer;
	}
	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	answer = ~sum;
	return (answer);
}


