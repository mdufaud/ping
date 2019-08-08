/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argfetch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 21:48:41 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_equal(char *arg)
{
	char	*s;

	s = ft_strrchr(arg, '=');
	return (ft_strdup(s + 1));
}

char		*ft_argfetch(int argc, char **argv, char *arg)
{
	int		i;
	int		mask;

	i = 1;
	mask = ARGFIND_STOP_FIRST | ARGFIND_ALL;
	while (i < argc)
	{
		if (ft_isarg(argv[i]) && ft_argfind(argv[i], arg, mask))
		{
			if (ft_strcfind(argv[i], '=') >= 0)
				return (get_equal(argv[i]));
			if (argv[i + 1])
				return (ft_strdup(argv[i + 1]));
		}
		i++;
	}
	return (NULL);
}
