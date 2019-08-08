/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:38:23 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/05 21:37:48 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

static int	ft_is_str(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
		if (!s2[i])
			return (1);
	}
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s2[0])
		return ((char *)s1);
	while (i < n)
	{
		if (s1[i] == s2[0])
		{
			if (ft_is_str(s1, s2, (n - i)))
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
