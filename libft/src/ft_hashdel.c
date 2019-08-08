/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:36:06 by mdufaud           #+#    #+#             */
/*   Updated: 2014/06/08 12:49:49 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	del_hash(t_hash **hash, t_hash *to_del)
{
	t_hash	*next;
	t_hash	*prev;

	next = to_del->next;
	prev = to_del->prev;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	ft_hashfree_value(to_del);
	free(to_del);
	if (prev)
		*hash = prev;
	else if (next)
		*hash = next;
	else
		*hash = NULL;
	return (1);
}

static int	first_hash(t_hash **hash)
{
	t_hash	*tmp;
	t_hash	*first;

	tmp = *hash;
	free(tmp->first);
	first = tmp->next;
	first->prev = NULL;
	tmp = tmp->next;
	while (tmp)
	{
		tmp->first = first;
		tmp = tmp->next;
	}
	*hash = first;
	return (1);
}

int			ft_hashdel(t_hash **hash, char *key)
{
	t_hash	*tmp;

	tmp = (*hash)->first;
	if (ft_strequ(tmp->key, key))
		return (first_hash(hash));
	tmp = tmp->next;
	while (tmp)
	{
		if (ft_strequ(tmp->key, key))
			return (del_hash(hash, tmp));
		tmp = tmp->next;
	}
	return (0);
}
