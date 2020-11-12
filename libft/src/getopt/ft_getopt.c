/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:10:03 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/15 20:52:17 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_getopt.h"
#include "libft_string.h"
#include "libft_printf.h"
#include "libft_io.h"
#include <unistd.h>

char		*g_optarg = NULL;
int			g_optopt = 0;
int			g_optind = 1;
int			g_optreset = 1;

static int		getopt_msg(const t_acav acav, const char*const name,
t_opterr err)
{
	if (err == REQUIRES_ARG)
		ft_printf_fd(STDERR_FILENO,
		"%s: option requires an argument -- %c\n", acav.av[0] + 2, name[0]);
	else if (err == UNRECOGNIZED_OPTION)
		ft_printf_fd(STDERR_FILENO,
		"%s: invalid option -- %c\n", acav.av[0] + 2, name[0]);
	return ('?');
}

static int		helper(const t_acav acav, const char *opstring,
const char **ptr)
{
	char	*op;

	if (!(op = ft_strchr(opstring, *(*ptr)++)))
	{
		getopt_msg(acav, *ptr - 1, UNRECOGNIZED_OPTION);
		(**ptr ? 0 : (*ptr = acav.av[++g_optind]));
		return ('?');
	}
	if (op[1] != ':')
		(**ptr ? 0 : (*ptr = acav.av[++g_optind]));
	else if (**ptr && (g_optarg = (char *)*ptr))
		*ptr = acav.av[++g_optind];
	else
	{
		if (++g_optind == acav.ac)
		{
			return (*opstring == ':' ? ':' :
			getopt_msg(acav, *ptr - 1, REQUIRES_ARG));
		}
		g_optarg = (char *)acav.av[g_optind];
		*ptr = acav.av[++g_optind];
	}
	return (*op);
}

void			ft_getoptreset(void)
{
	g_optarg = NULL;
	g_optopt = 0;
	g_optind = 1;
	g_optreset = 0;
}

int				ft_getopt(const t_acav acav, const char *optstring)
{
	const static char	*ptr;

	if (g_optreset)
		ft_getoptreset();
	if (!ptr || ptr < acav.av[g_optind])
		ptr = acav.av[g_optind];
	else
		ptr = (*ptr ? ptr : acav.av[++g_optind]);
	if (g_optind >= acav.ac || (ptr == acav.av[g_optind] &&
	*ptr++ != '-'))
		return (-1);
	if (!ft_strcmp(ptr, "-"))
	{
		ptr = acav.av[++g_optind];
		return (-1);
	}
	g_optopt = *ptr;
	return (helper(acav, optstring, &ptr));
}
