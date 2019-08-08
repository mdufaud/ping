/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:16:49 by mdufaud           #+#    #+#             */
/*   Updated: 2014/03/12 23:05:35 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*str1;
	const char	*str2;

	str1 = s1;
	str2 = s2;
	if (str2 < str1)
	{
		while (n--)
			*(str1 + n) = *(str2 + n);
	}
	else
		ft_memcpy(str1, str2, n);
	return (s1);
}
