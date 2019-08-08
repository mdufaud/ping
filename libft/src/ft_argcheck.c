/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 22:25:00 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_argcheck(char *arg, char **arglist, int sum)
{
	int		i;
	int		mult;

	i = 0;
	mult = 0;
	while (arglist[i])
	{
		if (!ft_strcmp(arglist[i], arg))
			return (sum & (2 << mult));
		mult++;
		i++;
	}
	return (0);
}
