/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 23:32:11 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/05 20:42:37 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_split(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && c == s[i])
			i++;
		if (s[i] && c != s[i])
			count++;
		while (s[i] && c != s[i])
			i++;
	}
	return (count);
}

static char		*ft_filltab(char const *s, int *j, char c)
{
	int	x;
	int	y;

	x = *j;
	while (s[x] && c == s[x])
		x++;
	y = x;
	while (s[y] && c != s[y])
		y++;
	*j = y;
	return (ft_strsub(s, x, y - x));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		splits;
	int		j;

	i = 0;
	j = 0;
	splits = ft_split(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (splits + 1))))
		return (NULL);
	while (splits--)
	{
		tab[i] = ft_filltab(s, &j, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
