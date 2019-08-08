/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 10:23:59 by mdufaud           #+#    #+#             */
/*   Updated: 2014/04/23 23:15:57 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_debugc(char *name, char c)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" : ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
}
