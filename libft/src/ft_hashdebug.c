/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashdebug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:36:04 by mdufaud           #+#    #+#             */
/*   Updated: 2015/01/26 17:30:46 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_hash_lst(t_hash *hash, int index)
{
	char	**tab;
	int		*lst;

	if (hash->type == type_lst)
	{
		lst = (int *)hash->value;
		ft_putnbr(lst[index]);
	}
	if (hash->type == type_tab)
	{
		tab = (char **)hash->value;
		ft_putstr(tab[index]);
	}
}

static void	print_hash_mono(t_hash *hash)
{
	ft_putstr("\tHash[\"");
	ft_putstr(hash->key);
	ft_putstr("\"] => ");
	if (hash->type == type_int)
		ft_putnbr(*((int *)hash->value));
	if (hash->type == type_char)
		ft_putchar(*((char *)(hash->value)));
	if (hash->type == type_str)
		ft_putstr((char *)hash->value);
	if (hash->type == type_addr)
		ft_printaddr(hash->value);
	ft_putchar('\n');
}

static void	print_hash_list(t_hash *hash)
{
	size_t		i;
	size_t		limit;

	ft_putstr("\tHash[\"");
	ft_putstr(hash->key);
	ft_putstr("\"] => \n");
	i = 0;
	limit = hash->size;
	while (i < limit)
	{
		ft_putstr("\t\ttab[");
		ft_putnbr(i);
		ft_putstr("] = ");
		print_hash_lst(hash, i);
		ft_putchar('\n');
		i++;
	}
}

static void	print_hash_size(t_hash *hash)
{
	if (hash->type == type_tab)
		ft_putnbr(ft_tabcount((char **)hash->value) + sizeof(char **));
	else if (hash->type == type_lst)
		ft_putnbr(hash->size * sizeof(int));
	else
		ft_putnbr(hash->size);
}

void		ft_hashdebug(t_hash *hash)
{
	ft_putcendl("Hash", white);
	ft_putcendl("{", white);
	ft_putstr("\tHash type : < ");
	ft_print_t_type(hash->type);
	ft_putstr(" > size : ");
	print_hash_size(hash);
	ft_putendl(" octets.");
	if (hash->type == type_int || hash->type == type_char
			|| hash->type == type_str || hash->type == type_addr)
		print_hash_mono(hash);
	if (hash->type == type_lst || hash->type == type_tab)
		print_hash_list(hash);
	ft_putcendl("}", white);
}
