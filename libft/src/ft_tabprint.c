/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:35:14 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/29 18:35:20 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabprint(char **tab)
{
	int	i;

	i = 0;
	if (!tab || !tab[0])
	{
		ft_putstr("Tab -> ");
		ft_putendl(NULL);
		return ;
	}
	while (tab[i])
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("] ");
		if (ft_tablen(tab) > 10 && i < 10)
			ft_putchar(' ');
		ft_putstr(": ");
		ft_putstr("'");
		ft_putstr(tab[i]);
		ft_putendl("'");
		i++;
	}
}
