/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_color_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 19:03:31 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/07 10:56:24 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_color_fd(int fd, t_color color)
{
	if (color == red)
		ft_putstr_fd("\033[31m", fd);
	else if (color == white)
		ft_putstr_fd("\033[37;01m", fd);
	else if (color == bourg)
		ft_putstr_fd("\033[31;01m", fd);
	else if (color == blue)
		ft_putstr_fd("\033[34;01m", fd);
	else if (color == dark)
		ft_putstr_fd("\033[30;01m", fd);
	else if (color == purple)
		ft_putstr_fd("\033[35m", fd);
	else if (color == cyan)
		ft_putstr_fd("\033[36;01m", fd);
	else if (color == yellow)
		ft_putstr_fd("\033[33;01m", fd);
	else if (color == green)
		ft_putstr_fd("\033[32m", fd);
	else if (color == pink)
		ft_putstr_fd("\033[35;01m", fd);
}
