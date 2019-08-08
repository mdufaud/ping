/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 19:03:31 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/07 10:56:24 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putcstr_fd(char *s, int fd, t_color color)
{
	ft_put_color_fd(fd, color);
	ft_putstr_fd(s, fd);
	ft_end_color_fd(fd);
}
