/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:41:31 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/05 20:42:16 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (!s[i])
		return (ft_strdup(""));
	j = i;
	while (s[j] && s[j + 1])
		j++;
	while (j >= 0 && ft_isspace(s[j]))
		j--;
	return (ft_strsub(s, i, ((j + 1) - i)));
}
