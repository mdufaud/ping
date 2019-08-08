/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_printbase(int n, int base)
{
	char	c;

	(void)base;
	if (n >= 10)
		c = n + 87;
	else
		c = n + 48;
	write(1, &c, 1);
}

void		ft_putbase(long n, int base)
{
	if (n < base)
		ft_printbase(n, base);
	else
	{
		ft_putbase(n / base, base);
		ft_printbase(n % base, base);
	}
}
