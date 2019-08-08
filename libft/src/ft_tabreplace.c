/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:35:45 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/29 18:35:48 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabreplace(char **tab, char *s, int index)
{
	char	*tmp;

	if (ft_tablen(tab) <= index)
		return (tab);
	tmp = tab[index];
	tab[index] = s;
	free(tmp);
	return (tab);
}
