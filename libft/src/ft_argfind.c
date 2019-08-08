/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:51:53 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 22:43:09 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_arg(char *arg, char *argv, int *index)
{
	int		i;

	i = 0;
	while (arg[i] && argv[i] && arg[i] == argv[i])
		i++;
	*index = i;
	if (!arg[i])
		return (1);
	return (0);
}

static int	is_doublearg(char *arg, char *argv, int *index)
{
	int		i;

	i = 0;
	while (arg[i] && argv[i] && arg[i] == argv[i])
		i++;
	*index = i;
	if (!arg[i] && (!argv[i] || argv[i] == '='))
		return (1);
	return (0);
}

static int	argfind_return(int ret, int index, int mask)
{
	if ((mask & ARGFIND_RET_INDEX))
		return (index);
	return (ret);
}

static char	*get_begin(char *s)
{
	if (ft_strcfind(s, '-') >= 0)
		return (ft_strchr(s, '-') + 1);
	return (s);
}

int			ft_argfind(char *argv, char *arg, int mask)
{
	int		i;
	int		ret;
	int		index;

	if ((i = is_doublearg(arg, argv, &index)))
		return (argfind_return(i, index, mask));
	argv = get_begin(argv);
	arg = get_begin(arg);
	i = 0;
	while (argv[i])
	{
		ret = is_arg(arg, argv + i, &index);
		if ((mask & ARGFIND_STOP_FALSE) && !ret)
			break ;
		if (((mask & ARGFIND_STOP_FIRST) && ret)
			|| !(mask & ARGFIND_ALL))
			break ;
		i++;
	}
	return (argfind_return(ret, i, mask));
}
