/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 14:21:03 by mdufaud           #+#    #+#             */
/*   Updated: 2014/04/26 15:03:41 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbin(long n)
{
	int		space;
	int		i;
	long	mask;

	i = 62;
	mask = 0x4000000000000000;
	space = 1;
	ft_putchar('0');
	while (i > 0)
	{
		ft_putchar(((n & mask) >> i) + 48);
		mask = mask >> 1;
		i--;
		space++;
		if (!(space % 4))
			ft_putchar(' ');
	}
	ft_putchar(((n & mask) >> i) + 48);
}
