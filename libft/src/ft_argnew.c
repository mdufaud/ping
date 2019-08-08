/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:32:20 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 21:23:44 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_arg		*ft_argnew(int argc, char **argv, char *argliststr)
{
	t_arg		*new;
	char		**arglist;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	if (!(arglist = ft_strsplit(argliststr, ' ')))
	{
		free(new);
		return (NULL);
	}
	new->argc = argc;
	new->argv = ft_tabdup(argv);
	new->sum = ft_argsum(argc, argv, arglist);
	new->arglist = arglist;
	new->fetch = ft_argfetch_fun;
	new->check = ft_argcheck_fun;
	new->get_error = ft_argerror;
	new->arg_add = ft_argadd;
	new->none = ft_argnone;
	new->error = NULL;
	new->error_sum = 0;
	return (new);
}
