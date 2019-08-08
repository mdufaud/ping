/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_verbose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:47:36 by mdufaud           #+#    #+#             */
/*   Updated: 2014/06/08 12:47:39 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_error_verbose(char *err, char *reason)
{
	char	*projname;

	projname = ft_projname(NULL);
	ft_putcstr(projname, white);
	ft_putcstr(" : ", white);
	ft_putcstr(err, red);
	ft_putcendl(reason, red);
	return (1);
}
