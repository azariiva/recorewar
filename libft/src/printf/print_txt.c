/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:55 by fhilary           #+#    #+#             */
/*   Updated: 2020/07/06 03:00:26 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include <stdbool.h>

int		calc_diff_s(t_pf *pf, char *str)
{
	int	diff;

	if (pf->prec > 0 && pf->prec < (int)ft_strlen(str))
		diff = pf->width - pf->prec;
	else if (pf->prec == -1)
		diff = pf->width;
	else
		diff = pf->width - ft_strlen(str);
	if (diff < 0)
		diff = 0;
	pf->len += diff;
	return (diff);
}

void	print_txt_s(t_pf *pf, char *str)
{
	int		diff;
	bool	free_b;

	if (!str)
	{
		str = ft_strdup("(null)");
		free_b = true;
	}
	else
		free_b = false;
	diff = calc_diff_s(pf, str);
	if (!(pf->flag & MIN_FLAG))
	{
		ft_putcharn_buf(&(pf->buf), pf->flag & ZERO_FLAG ? '0' : ' ', diff);
		diff = 0;
	}
	if (pf->prec != -1)
		pf->len += (pf->prec > 0 ? ft_putstrn_buf(&(pf->buf), str, \
					pf->prec) : ft_putstr_buf(&(pf->buf), str));
	if (diff > 0)
		ft_putcharn_buf(&(pf->buf), ' ', diff);
	if (free_b == true)
		ft_strdel(&str);
}

void	print_txt_c(t_pf *pf, char c)
{
	int		diff;

	diff = 0;
	if (pf->width > 0)
		diff = pf->width - 1;
	pf->len += diff;
	if (!(pf->flag & MIN_FLAG))
	{
		if (pf->flag & ZERO_FLAG)
			ft_putcharn_buf(&(pf->buf), '0', diff);
		else
			ft_putcharn_buf(&(pf->buf), ' ', diff);
		diff = 0;
	}
	pf->len++;
	ft_putchar_buf(&(pf->buf), c);
	ft_putcharn_buf(&(pf->buf), ' ', diff);
}
