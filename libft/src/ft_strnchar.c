/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 12:52:54 by mdufaud           #+#    #+#             */
/*   Updated: 2014/04/23 23:18:36 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strnchar(char *s, int n)
{
	char			c;
	unsigned int	i;
	unsigned int	count;

	c = (char)n;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}
