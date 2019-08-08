/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:36:02 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/29 18:36:19 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_hash	*hash_check(t_hash *old, t_hash *new, int *status)
{
	t_hash	*tmp;

	tmp = old;
	while (tmp)
	{
		if (ft_strequ(tmp->key, new->key))
		{
			tmp->value = new->value;
			tmp->type = new->type;
			tmp->size = new->size;
			free(new);
			*status = 1;
			return (old);
		}
		tmp = tmp->next;
	}
	return (old);
}

t_hash			*ft_hashadd(t_hash *old, t_hash *new)
{
	t_hash	*tmp;
	int		i;

	i = 0;
	if (old)
	{
		old = hash_check(old, new, &i);
		if (i == 1)
			return (old);
		tmp = old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->first = old;
	}
	else
	{
		new->prev = old;
		old = new;
		old->first = old;
	}
	return (old);
}
