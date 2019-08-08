/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 17:32:35 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 21:10:04 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	**ft_tabnew(size_t col)
{
	char	**tab;
	size_t	i;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (col + 1))))
		return (NULL);
	while (i < col)
	{
		tab[i] = 0;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
