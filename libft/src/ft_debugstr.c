/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 20:45:28 by mdufaud           #+#    #+#             */
/*   Updated: 2014/02/22 18:25:23 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_debugstr(char *s)
{
	ft_putchar_fd('\"', 2);
	if (!s)
		ft_putstr_fd("(null)", 2);
	else
		ft_putstr_fd(s, 2);
	ft_putchar_fd('\"', 2);
	ft_putchar_fd('\n', 2);
}
