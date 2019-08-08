/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 10:15:28 by mdufaud           #+#    #+#             */
/*   Updated: 2014/03/12 23:24:42 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEBUG_FUN ft_debugfun(__func__);

void	ft_debugstr(char *s);
void	ft_debugnbr(int n);
void	ft_debugchar(char c);
void	ft_debugs(char *name, char *s);
void	ft_debugn(char *name, int n);
void	ft_debugc(char *name, char c);
void	ft_debugfun(const char *s);
void	ft_debugstrn(const char *s, int until);
#endif
