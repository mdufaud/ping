/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:08:36 by mdufaud           #+#    #+#             */
/*   Updated: 2014/04/23 23:16:04 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]) && s[i] != ' ')
			s[i] = ' ';
		i++;
	}
	return (s);
}

char		*ft_epur(char *s)
{
	int		i;
	int		j;
	char	*tmp;
	char	*ret;

	i = 0;
	j = 0;
	if (!s || !s[0])
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	ret = s;
	s = ft_strtrim(s);
	ft_strdel(&ret);
	while (s[i])
	{
		tmp[j++] = s[i];
		i++;
		while (ft_isspace(s[i]) && ft_isspace(s[i + 1]))
			i++;
	}
	tmp[j] = 0;
	ret = ft_strdup(tmp);
	ret = ft_check(ret);
	ft_strdel(&tmp);
	return (ret);
}
