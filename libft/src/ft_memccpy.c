/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:19:40 by mdufaud           #+#    #+#             */
/*   Updated: 2014/03/12 23:03:30 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*str1;
	const char	*str2;

	str1 = s1;
	str2 = s2;
	while (n-- != 0)
	{
		if (*str2 != c)
		{
			*str1 = *str2;
			str1++;
			str2++;
		}
		else
		{
			*(str1++) = *str2;
			return (str1);
		}
	}
	return (NULL);
}
