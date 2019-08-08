/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:41:07 by mdufaud           #+#    #+#             */
/*   Updated: 2015/12/07 15:13:42 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int		gnl_read(t_line **gnl)
{
	char	buffer[GNL_BUFFER_SIZE + 1];
	int		ret;
	t_list	*lst;

	if ((ret = read((*gnl)->fd, buffer, GNL_BUFFER_SIZE)) > 0)
		buffer[ret] = 0;
	(*gnl)->ret = ret;
	if (ret < 0)
		return (-1);
	if (!(lst = ft_lstnew(buffer, ret + 1)))
		return (-1);
	lst->content_size -= 1;
	*((char *)lst->content + ret) = 0;
	lst->next = (*gnl)->read;
	(*gnl)->read = lst;
	return (ret);
}

static int		gnl_find(t_line **gnl, size_t *size)
{
	int		i;
	char	*s;

	if (!(*gnl)->read)
		return (0);
	s = (*gnl)->read->content;
	i = (*gnl)->i < 0 ? 0 : (*gnl)->i;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			(*gnl)->i = i;
			*size += i;
			return (1);
		}
		++i;
	}
	(*gnl)->i = -1;
	*size += i;
	return (0);
}

static int		gnl_get_line(t_line **gnl, char **line)
{
	size_t	size;
	t_list	*tmp;

	size = 0;
	(*gnl)->i = 0;
	while (!gnl_find(gnl, &size) && gnl_read(gnl) > 0)
		;
	if ((!size && !(*gnl)->ret) || (*gnl)->ret < 0)
		return ((*gnl)->ret);
	if (!(*line = ft_strnew(size)))
		return (-1);
	(*gnl)->i = (*gnl)->i == -1 ? (int)(*gnl)->read->content_size : (*gnl)->i;
	tmp = (*gnl)->read;
	gnl_fill_line(gnl, line, tmp, size);
	(*gnl)->read = tmp;
	return (gnl_prepare_next_line(gnl, tmp));
}

int				get_next_line(int const fd, char **line)
{
	static void		*first = NULL;
	t_line			*gnl;
	int				ret;

	if (fd < 0 || fd == 1 || !line)
		return (-1);
	*line = NULL;
	gnl = !first ? NULL : first;
	if (gnl && gnl->fd != fd)
		gnl_free(&gnl);
	if (!gnl && !gnl_alloc(&gnl, fd))
		return (-1);
	ret = gnl_get_line(&gnl, line);
	ret = ret <= 0 ? ret : 1;
	if (ret <= 0)
		gnl_free(&gnl);
	first = gnl;
	return (ret);
}
