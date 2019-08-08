/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sendendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 19:14:48 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/18 15:14:05 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include "libft.h"
#include <stdlib.h>

int		ft_sendendl(char *s, int socket)
{
	int		i;
	int		ret;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	str = ft_strjoin(s, "\n");
	ret = send(socket, str, i + 1, 0);
	free(str);
	return (ret);
}
