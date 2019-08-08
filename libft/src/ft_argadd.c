/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_argadd(t_arg *arg, char *s)
{
	char	**tab;

	if (!(tab = ft_strsplit(s, ' ')))
		return ;
	arg->arglist = ft_tabjoin(arg->arglist, tab);
	arg->sum = ft_argsum(arg->argc, arg->argv, arg->arglist);
}
