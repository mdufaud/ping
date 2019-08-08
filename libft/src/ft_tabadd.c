/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 15:32:09 by mdufaud           #+#    #+#             */
/*   Updated: 2014/06/13 16:02:25 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabadd(char **tab, char *s)
{
	char	**ret;
	int		i;

	ret = (char **)malloc(sizeof(char *) * (ft_tablen(tab) + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		ret[i] = tab[i];
		i++;
	}
	ret[i] = s;
	ret[i + 1] = 0;
	free(tab);
	return (ret);
}
