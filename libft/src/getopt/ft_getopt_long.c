/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:47:55 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/08 18:47:48 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_getopt.h"
#include "libft_string.h"
#include "libft_printf.h"
#include <unistd.h>

static int	getoptint(char *ptr, t_option *longopts)
{
	int	i;

	i = -1;
	while (longopts[++i].name != NULL)
	{
		if (!ft_strccmp(ptr, longopts[i].name, '='))
			return (i);
	}
	return (-1);
}

static int	getopt_msg(const t_acav acav, const char*const name,
t_opterr err)
{
	if (err == REQUIRES_ARG)
		ft_printf_fd(STDERR_FILENO,
		"%s: option `%s\' requires an argument\n", acav.av[0] + 2, name);
	else if (err == DOESNT_ALLOW_ARG)
		ft_printf_fd(STDERR_FILENO,
		"%s: option `%s\' doesn't allow an argument\n", acav.av[0] + 2, name);
	else if (err == UNRECOGNIZED_OPTION)
		ft_printf_fd(STDERR_FILENO,
		"%s: unrecognized option `%s\'\n", acav.av[0] + 2, name);
	return ('?');
}

static int	getopt_helper(const t_acav acav, const char*const shortopts,
t_option*const longopts, int i)
{
	if (g_optarg == NULL && longopts[i].has_arg == REQUIRED_ARGUMENT)
	{
		if (!((g_optarg = acav.av[g_optind]) && g_optind++))
		{
			return (*shortopts == ':' ? ':' :
			getopt_msg(acav, longopts[i].name, REQUIRES_ARG));
		}
	}
	if (longopts[i].flag)
	{
		*(longopts[i].flag) = longopts[i].val;
		return (0);
	}
	g_optopt = longopts[i].val;
	return (longopts[i].val);
}

int			ft_getopt_long(const t_acav acav, const char*const shortopts,
t_option*const longopts, int*const indexptr)
{
	char	*ptr;
	int		i;

	(!g_optind || g_optreset ? ft_getoptreset() : 0);
	if (g_optind >= acav.ac || acav.av[g_optind][0] != '-' || (g_optarg = NULL))
		return (-1);
	if (!longopts || acav.av[g_optind][1] != '-' || !acav.av[g_optind][2])
		return (ft_getopt(acav, shortopts));
	ptr = acav.av[g_optind] + 2;
	g_optind++;
	if ((i = getoptint(ptr, longopts)) != -1)
	{
		while (*ptr && *ptr != '=')
			ptr++;
		if (*ptr == '=')
		{
			if (!longopts[i].has_arg)
				return (getopt_msg(acav, longopts[i].name, DOESNT_ALLOW_ARG));
			g_optarg = ptr + 1;
		}
		(indexptr ? *indexptr = i : 0);
		return (getopt_helper(acav, shortopts, longopts, i));
	}
	return (getopt_msg(acav, acav.av[g_optind - 1], UNRECOGNIZED_OPTION));
}

int			ft_getopt_long_only(const t_acav acav, const char*const shortopts,
t_option*const longopts, int*const indexptr)
{
	char	*ptr;
	int		i;

	(!g_optind || g_optreset ? ft_getoptreset() : 0);
	if (g_optind >= acav.ac || acav.av[g_optind][0] != '-' || (g_optarg = NULL))
		return (-1);
	if (!(longopts && ((acav.av[g_optind][1] == '-' && acav.av[g_optind][2]) ||
	(acav.av[g_optind][1] && acav.av[g_optind][1] != '-'))))
		return (ft_getopt(acav, shortopts));
	(*(ptr = acav.av[g_optind] + 1) == '-') ? ptr++ : 0;
	if (++g_optind && (i = getoptint(ptr, longopts)) != -1)
	{
		while (*ptr && *ptr != '=')
			ptr++;
		if (*ptr == '=')
		{
			if (!longopts[i].has_arg)
				return (getopt_msg(acav, longopts[i].name, DOESNT_ALLOW_ARG));
			g_optarg = ptr + 1;
		}
		(indexptr ? *indexptr = i : 0);
		return (getopt_helper(acav, shortopts, longopts, i));
	}
	return (getopt_msg(acav, acav.av[g_optind - 1], UNRECOGNIZED_OPTION));
}
