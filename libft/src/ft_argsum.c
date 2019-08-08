/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argsum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 22:36:01 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sum(char *argv, char **arglist, int sum)
{
	int		i;
	int		mult;
	int		ret;
	int		mask;

	i = 0;
	mult = 0;
	ret = 0;
	mask = ARGFIND_STOP_FIRST | ARGFIND_ALL;
	while (arglist[i])
	{
		if (ft_isarg(argv) == ft_isarg(arglist[i])
			&& ft_argfind(argv, arglist[i], mask)
			&& !(sum & (2 << mult)))
			ret += 2 << mult;
		mult++;
		i++;
	}
	return (ret);
}

int			ft_argsum(int argc, char **argv, char **arglist)
{
	int		i;
	int		sum;

	i = 1;
	sum = 0;
	while (i < argc)
	{
		sum += get_sum(argv[i], arglist, sum);
		i++;
	}
	return (sum);
}
