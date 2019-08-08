/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2016/02/16 16:11:57 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_error(char *argv, char **alst)
{
	int	error;
	int	i;

	i = 0;
	error = 0;
	while (alst[i])
	{
		if (!error)
			error = ft_argfind(argv, alst[i], ARGFIND_STOP_FALSE);
		i++;
	}
	return (error);
}

static char	*make_error(char *argv, int index, int type)
{
	int		until;

	until = type >= 2 ? ft_strlen(argv) : 1;
	argv = argv + index;
	if (type < 2 && argv[0] == '-')
		argv += 1;
	return (ft_strsub(argv, 0, until));
}

static char	*find_in_arglist(t_arg *arg, char *argv)
{
	int		j;
	int		error;
	char	**alst;
	int		type;

	j = 0;
	type = ft_isarg(argv);
	alst = arg->arglist;
	if (type >= 2)
		error = is_error(argv, alst);
	while (argv[j] && type < 2 && (error = is_error(argv + j, alst)))
		j++;
	if (!error)
		return (make_error(argv, j, type));
	return (NULL);
}

void		ft_argerror(t_arg *arg)
{
	int		i;
	char	*err;

	i = 1;
	while (i < arg->argc)
	{
		if (ft_isarg(arg->argv[i])
			&& (err = find_in_arglist(arg, arg->argv[i])))
		{
			if (!(arg->error_sum & ARG_INVALID_OPTION))
			{
				arg->error = ft_strjoin("invalid option -- ", err);
				arg->error_sum += ARG_INVALID_OPTION;
			}
			ft_strdel(&err);
			break ;
		}
		i++;
	}
}
