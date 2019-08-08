/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:47:23 by mdufaud           #+#    #+#             */
/*   Updated: 2014/06/08 12:47:29 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_error_file(char *error, char *file)
{
	char	*projname;

	projname = ft_projname(NULL);
	ft_putcstr(projname, white);
	ft_putstr(" : ");
	ft_putcstr(error, red);
	ft_putcstr(" (in file ", white);
	ft_putcstr(file, white);
	ft_putcendl(" ).", white);
	return (1);
}
