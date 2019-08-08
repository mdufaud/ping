/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 10:22:49 by mdufaud           #+#    #+#             */
/*   Updated: 2014/02/08 19:45:22 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "debug.h"

void	ft_debugn(char *name, int n)
{
	if (n > 2147483647)
	{
		ft_putstr_fd("Careful, the number '", 2);
		ft_putstr_fd(name, 2);
		ft_putendl_fd("' is higher than int", 2);
		return ;
	}
	if (n < -2147483647)
	{
		ft_putstr_fd("Careful, the number '", 2);
		ft_putstr_fd(name, 2);
		ft_putendl_fd("' is lower than int", 2);
		return ;
	}
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" : ", 2);
	ft_debugnbr(n);
}
