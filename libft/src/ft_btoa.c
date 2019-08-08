/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2016/02/16 16:11:22 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_fillnbr(char *s, long long n, int base, int mask)
{
	int			i;
	int			j;
	long long	tmp;

	i = ft_numsize(n, base);
	while (i)
	{
		j = i - 1;
		tmp = n;
		while (j-- && tmp >= base)
			tmp = tmp / base;
		*s = ft_basechar((tmp % base), 0);
		if ((mask & UPPER))
			*s = *s - ('a' - 'A');
		i--;
		s++;
	}
	*s = '\0';
}

char		*ft_btoa(long long n, int base, int mask)
{
	char	*s;
	char	*ptr;
	int		is_neg;
	int		size;

	is_neg = n < 0 ? 1 : 0;
	n = n < 0 ? n * -1 : n;
	size = ft_numsize(n, base);
	size = (mask & HEXA) ? size + 2 : size;
	if (!(s = ft_strnew(size)))
		return (NULL);
	ptr = s;
	if (is_neg)
		*(s++) = '-';
	else if ((mask & HEXA))
		s = ft_strcat(s, "0x");
	else if ((mask & HEXA_UPPER))
		s = ft_strcat(s, "0X");
	if ((mask & HEXA_UPPER) || (mask & HEXA))
		s = s + 2;
	ft_fillnbr(s, n, base, mask);
	return (ptr);
}
