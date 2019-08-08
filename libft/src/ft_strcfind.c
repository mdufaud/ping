/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:32:35 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 21:35:14 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strcfind(const char *s, int n)
{
	int		i;
	char	c;

	i = 0;
	c = (char)n;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}