/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 19:02:05 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/07 10:56:43 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_color(t_color color)
{
	if (color == red)
		ft_putstr("\033[31m");
	else if (color == bourg)
		ft_putstr("\033[31;01m");
	else if (color == white)
		ft_putstr("\033[37;01m");
	else if (color == blue)
		ft_putstr("\033[34;01m");
	else if (color == dark)
		ft_putstr("\033[30;01m");
	else if (color == purple)
		ft_putstr("\033[35m");
	else if (color == cyan)
		ft_putstr("\033[36;01m");
	else if (color == yellow)
		ft_putstr("\033[33;01m");
	else if (color == green)
		ft_putstr("\033[32m");
	else if (color == pink)
		ft_putstr("\033[35;01m");
}
