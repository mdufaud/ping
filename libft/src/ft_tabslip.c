/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabslip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:35:51 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/29 18:35:52 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabslip(char **tab, char *s, int index)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new = (char **)malloc(sizeof(char *) * (ft_tablen(tab) + 2))))
		return (NULL);
	while (tab[i])
	{
		if (i == index)
			new[j] = s;
		if (i == index)
			j++;
		new[j] = tab[i];
		i++;
		j++;
	}
	free(tab);
	new[j] = 0;
	return (new);
}
