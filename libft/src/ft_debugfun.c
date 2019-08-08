/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugfun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 10:32:15 by mdufaud           #+#    #+#             */
/*   Updated: 2014/02/08 19:37:26 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_debugfun(const char *s)
{
	static int	i = 0;

	ft_putstr_fd("Entering '", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("' step [", 2);
	ft_putnbr_fd(i, 2);
	ft_putstr_fd("]", 2);
	ft_putchar_fd('\n', 2);
	i++;
}
