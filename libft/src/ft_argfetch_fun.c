/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argfetch_fun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:52:23 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 21:41:25 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*multiple_fetch(t_arg *arg, char *s)
{
	char	**tab;
	int		i;
	char	*ret;

	i = 0;
	if (!(tab = ft_strsplit(s, ' ')))
		return (NULL);
	ret = NULL;
	while (tab[i])
	{
		ret = ft_argfetch(arg->argc, arg->argv, tab[i]);
		if (ret)
			break ;
		i++;
	}
	ft_tabfree(&tab);
	return (ret);
}

char		*ft_argfetch_fun(t_arg *arg, char *s)
{
	if (ft_strcfind(s, ' ') >= 0)
		return (multiple_fetch(arg, s));
	return (ft_argfetch(arg->argc, arg->argv, s));
}
