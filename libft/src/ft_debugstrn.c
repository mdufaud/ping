/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugstrn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 20:16:30 by mdufaud           #+#    #+#             */
/*   Updated: 2014/03/12 23:25:57 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <unistd.h>

void	ft_debugstrn(const char *s, int until)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(2, "(null)\n", 7);
		return ;
	}
	if (until > (int)ft_strlen(s))
	{
		ft_putstr_fd("ft_debugstrn: until too high (previous : ", 2);
		ft_putnbr_fd(until, 2);
		ft_putstr_fd(" / now : ", 2);
		until = ft_strlen(s);
		ft_putnbr_fd(until, 2);
		ft_putstr_fd(" )\n", 2);
	}
	ft_putstr_fd("'", 2);
	while (i <= until)
		i++;
	write(2, s, i);
	ft_putstr_fd("'\n", 2);
}
