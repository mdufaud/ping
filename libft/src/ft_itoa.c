/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:01:30 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/05 21:51:23 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	numsize(int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static void	ft_fillnbr(char *s, int n, int is_neg, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (is_neg)
		s[i++] = '-';
	while (i < size)
	{
		j = (size - i) - 1;
		tmp = n;
		while (j-- && tmp >= 10)
			tmp = tmp / 10;
		s[i] = (tmp % 10) + 48;
		i++;
	}
	s[i] = 0;
}

char		*ft_itoa(int n)
{
	char	*s;
	int		size;
	int		is_neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = n < 0 ? 1 : 0;
	n = ABS(n);
	size = numsize(n);
	size = is_neg ? size + 1 : size;
	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_fillnbr(s, n, is_neg, size);
	return (s);
}
