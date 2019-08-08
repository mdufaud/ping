/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 18:51:12 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/18 17:53:25 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

static char	*ft_getcolor(t_color color)
{
	if (color == red)
		return ("\033[31m");
	else if (color == bourg)
		return ("\033[31;01m");
	else if (color == white)
		return ("\033[37;01m");
	else if (color == blue)
		return ("\033[34;01m");
	else if (color == dark)
		return ("\033[30;01m");
	else if (color == purple)
		return ("\033[35m");
	else if (color == cyan)
		return ("\033[36;01m");
	else if (color == yellow)
		return ("\033[33;01m");
	else if (color == green)
		return ("\033[32m");
	else if (color == pink)
		return ("\033[35;01m");
	return ("");
}

void		ft_csend(char *s, t_color color, int co)
{
	char	*tmp;

	tmp = ft_strtjoin(ft_getcolor(color),
			s, "\033[00m\n");
	ft_send(tmp, co);
	free(tmp);
}
