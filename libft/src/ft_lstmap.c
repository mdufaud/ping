/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 19:26:34 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/05 20:43:30 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_lstgetsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static t_list	*ft_lstgetelement(t_list *lst, unsigned int index)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		if (i == index)
			break ;
		i++;
		lst = lst->next;
	}
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*s;
	t_list	*next;
	int		i;

	i = ft_lstgetsize(lst);
	s = NULL;
	while (i)
	{
		next = (*f)(ft_lstgetelement(lst, i - 1));
		next->next = s;
		s = next;
		i--;
	}
	return (s);
}
