/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:44:31 by mdufaud           #+#    #+#             */
/*   Updated: 2014/04/23 23:18:27 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(char **s, char const *s2)
{
	char	*str;
	int		i;
	char	*s1;

	s1 = *s;
	if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *(s1++);
	while (s2 && *s2)
		str[i++] = *(s2++);
	str[i] = '\0';
	ft_strdel(s);
	return (str);
}
