/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:36:16 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/29 18:36:19 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*current_key(void)
{
	static int	key = 0;

	key++;
	return (ft_itoa(key));
}

t_hash		*ft_hashnew(char *key, void *data, t_type type, size_t size)
{
	t_hash	*new;

	if (!(new = (t_hash *)malloc(sizeof(t_hash))))
		return (NULL);
	if (!key)
		new->key = current_key();
	else
		new->key = key;
	new->value = data;
	new->type = type;
	new->size = size;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
