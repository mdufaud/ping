/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 11:26:06 by mdufaud           #+#    #+#             */
/*   Updated: 2014/03/12 23:06:25 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(int *l, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr("List[");
		ft_putnbr(i);
		ft_putstr("] : ");
		ft_putnbr(l[i]);
		ft_putchar('\n');
		i++;
	}
}
