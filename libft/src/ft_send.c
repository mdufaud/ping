/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 19:14:48 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/17 16:04:32 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>

int		ft_send(char *s, int socket)
{
	int	i;
	int	ret;

	i = 0;
	while (s[i])
		i++;
	ret = send(socket, s, i, 0);
	return (ret);
}
