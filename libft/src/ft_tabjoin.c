/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabjoin(char **tab1, char **tab2)
{
	char	**ret;
	int		i;
	int		j;
	int		size;

	size = ft_tablen(tab1) + ft_tablen(tab2) + 1;
	if (!(ret = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	i = 0;
	while (tab1[i])
	{
		ret[i] = tab1[i];
		i++;
	}
	j = 0;
	while (tab2[j])
	{
		ret[i] = tab2[j];
		i++;
		j++;
	}
	free(tab1);
	free(tab2);
	ret[i] = 0;
	return (ret);
}
