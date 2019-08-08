/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_arglst(char *argv, char **alst)
{
	int		i;
	int		error;

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

int			ft_argsearch(char *argv, char **alst)
{
	int		j;
	int		error;
	int		type;

	j = 0;
	type = ft_isarg(argv);
	if (type >= 2)
		error = check_arglst(argv, alst);
	while (argv[j] && type < 2 && (error = check_arglst(argv + j, alst)))
		j++;
	return (error);
}
