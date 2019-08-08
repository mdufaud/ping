/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:36:08 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/29 18:36:12 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hashfind_type(t_hash **hash, t_type type)
{
	t_hash	*tmp;

	tmp = *hash;
	if (tmp->type == type)
		tmp = tmp->next;
	else
		tmp = tmp->first;
	while (tmp)
	{
		if (tmp->type == type)
		{
			*hash = tmp;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		ft_hashfind(t_hash **hash, char *key)
{
	t_hash	*tmp;

	tmp = *hash;
	tmp = tmp->first;
	while (tmp)
	{
		if (ft_strequ(tmp->key, key))
		{
			*hash = tmp;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
