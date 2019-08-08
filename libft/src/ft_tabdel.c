/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:34:58 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/29 18:34:59 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabdel(char **tab, int index)
{
	char	**new;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if ((size = ft_tablen(tab)) == 0)
		return (tab);
	if (!(new = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (tab[i])
	{
		new[j] = tab[i];
		j++;
		i++;
		if (i == index && tab[i])
			i++;
	}
	free(tab[index]);
	new[j] = 0;
	free(tab);
	return (new);
}
