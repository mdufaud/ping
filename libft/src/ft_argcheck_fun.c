/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcheck_fun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:51:18 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 21:41:12 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	multiple_args(t_arg *arg, char *s)
{
	char	**tab;
	int		error;
	int		i;

	i = 0;
	error = 0;
	if (!(tab = ft_strsplit(s, ' ')))
		return (-1);
	while (tab[i])
	{
		if (!error)
			error = ft_argcheck(tab[i], arg->arglist, arg->sum);
		i++;
	}
	ft_tabfree(&tab);
	return (error);
}

int			ft_argcheck_fun(t_arg *arg, char *s)
{
	if (ft_strcfind(s, ' ') >= 0)
		return (multiple_args(arg, s));
	return (ft_argcheck(s, arg->arglist, arg->sum));
}
