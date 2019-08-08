/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:34:55 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/29 18:34:56 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabcount(char **tab)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tab[i])
	{
		count += ft_strlen(tab[i]);
		i++;
	}
	return (count);
}
