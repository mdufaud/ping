/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 10:21:12 by mdufaud           #+#    #+#             */
/*   Updated: 2014/02/08 19:43:17 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "debug.h"

void	ft_debugs(char *name, char *s)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" : ", 2);
	ft_debugstr(s);
}
