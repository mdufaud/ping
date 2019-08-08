/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:47:15 by mdufaud           #+#    #+#             */
/*   Updated: 2014/06/08 12:47:19 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_error(char *error)
{
	char	*projname;

	projname = ft_projname(NULL);
	ft_putcstr(projname, white);
	ft_putcstr(" : ", white);
	ft_putcendl(error, red);
	return (1);
}
