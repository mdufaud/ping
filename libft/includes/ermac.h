/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ermac.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 12:48:46 by mdufaud           #+#    #+#             */
/*   Updated: 2014/06/08 12:49:39 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERMAC_H
# define ERMAC_H

# define FT_ERROR(error) ft_error_verbose(error, __FILE__)

int	ft_error(char *error);
int	ft_error_verbose(char *error, char *file);

#endif
