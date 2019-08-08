/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_t_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:47:42 by mdufaud           #+#    #+#             */
/*   Updated: 2014/06/13 15:39:03 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_t_type(t_type type)
{
	if (type == type_int)
		ft_putstr("int");
	if (type == type_char)
		ft_putstr("char");
	if (type == type_addr)
		ft_putstr("address");
	if (type == type_lst)
		ft_putstr("integer list");
	if (type == type_str)
		ft_putstr("string");
	if (type == type_tab)
		ft_putstr("array");
}
