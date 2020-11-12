/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:38:28 by fhilary           #+#    #+#             */
/*   Updated: 2020/07/06 02:42:06 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include "libft_memory.h"

static int	bold_colors(t_pf *pf, char *color)
{
	if (ft_strequ(color, "{bold red}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_BOLD_RED);
	else if (ft_strequ(color, "{bold green}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_BOLD_GREEN);
	else if (ft_strequ(color, "{bold yellow}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_BOLD_YELLOW);
	else if (ft_strequ(color, "{bold blue}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_BOLD_BLUE);
	else if (ft_strequ(color, "{bold magenta}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_BOLD_MAGENTA);
	else if (ft_strequ(color, "{bold cyan}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_BOLD_CYAN);
	else
		return (0);
	return (1);
}

static int	check_color(t_pf *pf, char *color)
{
	if (ft_strequ(color, "{red}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_RED);
	else if (ft_strequ(color, "{green}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_GREEN);
	else if (ft_strequ(color, "{yellow}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_YELLOW);
	else if (ft_strequ(color, "{blue}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_BLUE);
	else if (ft_strequ(color, "{magenta}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_MAGENTA);
	else if (ft_strequ(color, "{cyan}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_CYAN);
	else if (ft_strequ(color, "{eoc}"))
		pf->len += ft_putstr_buf(&(pf->buf), ANSI_EOC);
	else if (!bold_colors(pf, color))
		return (0);
	return (1);
}

void		print_color(t_pf *pf, const char *fmt, int *i)
{
	char	*ptr;
	char	*color;

	if ((ptr = ft_strchr(fmt + *i, '}')))
	{
		color = ft_strsub(fmt, *i, (size_t)(ptr + 1 - *i - fmt));
		if (check_color(pf, color))
			*i = ptr - fmt + 1;
		ft_memdel((void **)&color);
	}
}
