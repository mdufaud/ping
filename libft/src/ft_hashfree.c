/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:36:14 by mdufaud           #+#    #+#             */
/*   Updated: 2014/06/13 15:38:52 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_hashfree_value(t_hash *hash)
{
	char	**tab;

	if (hash->type == type_tab)
		tab = (char **)hash->value;
	if (hash->type == type_tab)
		ft_tabfree(&tab);
	else if (hash->type == type_str || hash->type == type_lst)
		free(hash->value);
}

void	ft_hashfree_allocated(t_hash **hash)
{
	t_hash	*tmp;
	t_hash	*to_free;

	tmp = *hash;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		ft_hashfree_value(to_free);
		free(to_free);
		to_free = NULL;
	}
	*hash = NULL;
}

void	ft_hashfree(t_hash **hash)
{
	t_hash	*tmp;
	t_hash	*to_free;

	tmp = *hash;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
		to_free = NULL;
	}
	*hash = NULL;
}
