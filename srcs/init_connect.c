/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_connect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:36:12 by mdufaud           #+#    #+#             */
/*   Updated: 2016/02/16 19:30:08 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

static void	fill_hints(struct addrinfo *hints)
{
	ft_bzero(hints, sizeof(struct addrinfo));
	hints->ai_family = AF_UNSPEC;
	hints->ai_socktype = SOCK_RAW;
	hints->ai_flags = AI_CANONNAME;
	hints->ai_canonname = NULL;
	hints->ai_addr = NULL;
	hints->ai_next = NULL;
	hints->ai_protocol = 0;

}

static int	interrogate_dns(t_env *env)
{
	struct addrinfo		hints;
	struct addrinfo		*results;
	struct addrinfo		*res;
	struct sockaddr_in6	*addr_in6;
	struct sockaddr_in	*addr_in;
	int					ret;
	char				str[INET6_ADDRSTRLEN];
	int					access_ipv6;
	int					i;

	env->exact_host = 0;
	access_ipv6 = 0;
	i = 0;
	fill_hints(&hints);
	if ((ret = getaddrinfo(env->host, NULL, &hints, &results)))
		return (error_j("unknown host ", env->host));
	res = results;
	while (results)
	{
		i++;
		if (access_ipv6 && (results->ai_family == AF_INET6))
		{
			env->family = results->ai_family;
			addr_in6 = (struct sockaddr_in6 *)results->ai_addr;
			env->addr6 = ft_strdup(inet_ntop(AF_INET6, &(addr_in6->sin6_addr), str, INET6_ADDRSTRLEN));
			if (results->ai_canonname)
				env->canonname6 = ft_strdup(results->ai_canonname);
		}
		else if ((results->ai_family == AF_INET))
		{
			env->family = results->ai_family;
			addr_in = (struct sockaddr_in *)results->ai_addr;
			env->addr = ft_strdup(inet_ntop(AF_INET, &(addr_in->sin_addr), str, INET_ADDRSTRLEN));
			if (results->ai_canonname)
				env->canonname = ft_strdup(results->ai_canonname);
			break ;
		}
		results = results->ai_next;
	}
	freeaddrinfo(res);
	if (!results && i)
		return (error_j("unknown host ", env->host));
	if (access_ipv6 && env->family == AF_INET6)
		env->inet = inet_pton(AF_INET6, env->addr6, &env->addr_in6.sin6_addr);
	else if (env->family == AF_INET)
		env->inet = inet_pton(AF_INET, env->addr, &env->addr_in.sin_addr);
	return (0);
}

static char	*get_host(t_arg *args)
{
	int		i;

	i = 1;
	while (i < args->argc)
	{
		if (args->argv[i][0] == '-'
			&& (!ft_strcmp(args->argv[i], "-c")
			|| !ft_strcmp(args->argv[i], "-i")
			|| !ft_strcmp(args->argv[i], "-t")))
			i += 2;
		if (i < args->argc && args->argv[i][0] != '-')
			return (ft_strdup(args->argv[i]));
		i++;
	}
	return (ft_strdup(args->argv[args->argc - 1]));
}

int			init_connect(t_env *env)
{
	int			ret;

	ret = 0;
	env->exact_host = 1;
	if (!(env->host = get_host(env->arg)))
		return (error("no address specified"));
	env->addr6 = NULL;
	env->addr = NULL;
	env->canonname = NULL;
	env->canonname6 = NULL;
	ft_bzero(&env->addr_in, sizeof(env->addr_in));
	env->addr_in.sin_family = AF_INET;
	ft_bzero(&env->addr_in6, sizeof(env->addr_in6));
	env->addr_in6.sin6_family = AF_INET6;
	if (!(env->inet = inet_pton(AF_INET, env->host, &env->addr_in.sin_addr)))
		ret = interrogate_dns(env);
	else
	{
		env->family = AF_INET;
		env->addr = ft_strdup(env->host);
	}
	return (ret);
}
