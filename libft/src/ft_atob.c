/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_to_index(const char *s, int base, int *neg)
{
	int		i;

	i = 0;
	*neg = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (base <= 10 && s[i] && (s[i] == '-' || s[i] == '+'))
	{
		*neg = s[i] == '-' ? 1 : 0;
		i++;
	}
	if (base > 10 && s[i] && s[i] == '+')
		i++;
	if (base > 10 && s[i] && s[i + 1]
		&& s[i] == '0' && ft_tolower(s[i + 1]) == 'x')
		i += 2;
	return (i);
}

long long	ft_atob(const char *s, int base)
{
	long long	val;
	int			neg;
	int			i;

	val = 0;
	i = get_to_index(s, base, &neg);
	while (s[i] && ft_isbase(s[i], base))
	{
		val = (val * base) + ft_getbase(s[i]) % base;
		i++;
	}
	if (neg)
		val = val * -1;
	return (val);
}
