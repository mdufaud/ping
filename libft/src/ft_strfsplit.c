/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 23:32:11 by mdufaud           #+#    #+#             */
/*   Updated: 2014/04/23 23:42:31 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_split(char const *s, int (*f)(char))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && f(s[i]))
			i++;
		if (s[i] && !f(s[i]))
			count++;
		while (s[i] && !f(s[i]))
			i++;
	}
	return (count);
}

static char		*ft_filltab(char const *s, int *j, int (*f)(char))
{
	int	x;
	int	y;

	x = *j;
	while (s[x] && f(s[x]))
		x++;
	y = x;
	while (s[y] && !f(s[y]))
		y++;
	*j = y;
	return (ft_strsub(s, x, y));
}

char			**ft_strfsplit(char const *s, int (*f)(char))
{
	char	**tab;
	int		i;
	int		splits;
	int		j;

	i = 0;
	j = 0;
	splits = ft_split(s, f);
	tab = (char **)malloc(sizeof(char *) * (splits + 1));
	while (splits--)
	{
		tab[i] = ft_filltab(s, &j, f);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
