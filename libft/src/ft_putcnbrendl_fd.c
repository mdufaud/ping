/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcnbrendl_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 19:02:05 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/07 10:56:43 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcnbrendl_fd(int n, int fd, t_color color)
{
	ft_put_color_fd(fd, color);
	ft_putnbr_fd(n, fd);
	ft_end_color_fd(fd);
	ft_putchar_fd('\n', fd);
}
