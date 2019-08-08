/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argnone                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2016/02/16 17:02:00 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_argnone(t_arg *arg)
{
	char	**tab;
	int		i;

	i = 1;
	tab = NULL;
	while (i < arg->argc)
	{
		if (ft_argsearch(arg->argv[i], arg->arglist) && arg->argv[i + 1])
			tab = ft_tabadd(tab, arg->argv[i + 1]);
		i++;
	}
	return (tab);
}
