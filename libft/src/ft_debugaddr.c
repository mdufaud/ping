/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 04:04:42 by mdufaud           #+#    #+#             */
/*   Updated: 2014/04/24 04:05:39 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_debugaddr(char *s, void *addr)
{
	ft_putstr(s);
	ft_putstr(" : ");
	ft_printaddr(addr);
	ft_putchar('\n');
}
