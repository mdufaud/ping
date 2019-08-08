/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:54:32 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/05 17:10:45 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (n < ft_strlen(s2))
	{
		while (s1[i])
			i++;
		j = 0;
		while (j < n)
		{
			s1[i++] = s2[j];
			j++;
		}
	}
	else
		return (ft_strcat(s1, s2));
	s1[i] = 0;
	return (s1);
}
