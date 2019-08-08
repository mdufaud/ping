/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:19:42 by mdufaud           #+#    #+#             */
/*   Updated: 2016/02/16 19:08:00 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

static int	usage(void)
{
	ft_putendl("Usage: sudo ./ft_ping [-vhaqctiA] address\n\
Options:\n\
\t-h help\n\
\t-c number of packet to transmit\n\
\t-i timing interval\n\
\t-t time to live value\n\
\t-A adaptive ping (spam)\n\
\t-q quiet output\n\
\t-v verbose output");
	return (1);
}

static int	toor(void)
{
	ft_putendl("You must be root to open a SOCKET_RAW");
	return (1);
}

int			main(int argc, char **argv)
{
	t_arg	*arg;
	t_env	env;

	if (argc < 2)
		return (usage());
	if (getuid() != 0)
		return (toor());
	if (!(arg = ft_argnew(argc, argv, "-v -h -a -q -c -t -i -A")))
		return (error("could not allocate arguments"));
	if (arg->check(arg, "-h"))
		return (usage());
	arg->get_error(arg);
	if (arg->error)
		return (error(arg->error));
	env.arg = arg;
	if (init_connect(&env))
		return (1);
	get_env(&env);
	set_ping(&env);
	return (0);
}
