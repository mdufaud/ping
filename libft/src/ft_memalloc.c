/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:38:34 by mdufaud           #+#    #+#             */
/*   Updated: 2015/01/27 16:53:25 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*v;
	char	*s;
	size_t	i;

	if (!size)
		return (NULL);
	v = malloc(size);
	if (!v)
		return (NULL);
	i = 0;
	s = (char *)v;
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
	return (v);
}
