/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 19:07:24 by mdufaud           #+#    #+#             */
/*   Updated: 2015/02/10 14:26:09 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define GNL_BUFFER_SIZE 4096

# include "libft.h"

# ifndef GNL_STRUCT
#  define GNL_STRUCT

typedef struct	s_line
{
	t_list		*read;
	int			i;
	int			last;
	int			ret;
	int			fd;
}				t_line;

# endif

int				get_next_line(int const fd, char **line);
int				gnl_free(t_line **gnl);
int				gnl_alloc(t_line **gnl, int fd);
int				gnl_prepare_next_line(t_line **gnl, t_list *tmp);
void			gnl_fill_line(t_line **g, char **l, t_list *t, size_t s);
#endif
