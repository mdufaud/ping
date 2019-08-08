/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:02:10 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/05 17:10:23 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (ft_strlen(dst) >= size)
	{
		i = size + ft_strlen(src);
		return (i);
	}
	else
		i = ft_strlen(dst) + ft_strlen(src);
	if (i >= size)
	{
		ft_strncat(dst, src, (size - ft_strlen(dst) - 1));
		return (i);
	}
	else
	{
		ft_strcat(dst, src);
		return (i);
	}
}
