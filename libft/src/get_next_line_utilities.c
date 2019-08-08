/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2016/02/16 16:09:34 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int		gnl_free(t_line **gnl)
{
	t_list		*tmp;

	while ((*gnl)->read)
	{
		free((*gnl)->read->content);
		tmp = (*gnl)->read;
		(*gnl)->read = (*gnl)->read->next;
		free(tmp);
	}
	free(*gnl);
	*gnl = NULL;
	return (1);
}

int		gnl_alloc(t_line **gnl, int fd)
{
	if (!(*gnl = malloc(sizeof(t_line))))
		return (0);
	(*gnl)->read = NULL;
	(*gnl)->fd = fd;
	(*gnl)->i = 0;
	(*gnl)->last = 0;
	(*gnl)->ret = 1;
	return (1);
}

int		gnl_prepare_next_line(t_line **gnl, t_list *tmp)
{
	char	*s;

	if (!(*((char *)tmp->content + (*gnl)->i)))
		(*gnl)->last = (*gnl)->i;
	else
		(*gnl)->last = (*gnl)->i + 1;
	if ((*gnl)->read->content_size == (unsigned int)(*gnl)->last)
	{
		free((*gnl)->read->content);
		free((*gnl)->read);
		(*gnl)->read = NULL;
	}
	else
	{
		s = (*gnl)->read->content;
		(*gnl)->read->content = ft_memcpy(s, tmp->content + (*gnl)->last,\
			tmp->content_size - (*gnl)->last + 1);
		(*gnl)->read->content_size = tmp->content_size - ((*gnl)->last);
		(*gnl)->read->next = NULL;
		(*gnl)->last = 0;
	}
	return (1);
}

void	gnl_fill_line(t_line **gnl, char **line, t_list *tmp, size_t size)
{
	t_list	*to_free;

	while ((*gnl)->read && size > 0)
	{
		to_free = (*gnl)->read == tmp ? NULL : (*gnl)->read;
		if ((*gnl)->read == tmp)
			ft_memcpy(*line + (size - ((*gnl)->i)),\
						(*gnl)->read->content, (*gnl)->i);
		else
			ft_memcpy(*line + (size - (*gnl)->read->content_size),\
						(*gnl)->read->content, (*gnl)->read->content_size);
		if ((*gnl)->read == tmp)
			size = size - (*gnl)->i;
		else
			size = size - (*gnl)->read->content_size;
		(*gnl)->read = (*gnl)->read->next;
		if (to_free)
			ft_memdel(&to_free->content);
		free(to_free);
	}
}
