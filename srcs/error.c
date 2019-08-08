/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:21:17 by mdufaud           #+#    #+#             */
/*   Updated: 2016/02/16 19:12:26 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		error(char *err)
{
	ft_putcstr_fd("ft_ping: ", 2, white);
	ft_putcstr_fd("error: ", 2, red);
	ft_putendl_fd(err, 2);
	return (1);
}

int		error_j(char *err, char *s)
{
	ft_putcstr_fd("ft_ping: ", 2, white);
	ft_putcstr_fd("error: ", 2, red);
	ft_putstr_fd(err, 2);
	ft_putendl_fd(s, 2);
	return (1);
}
