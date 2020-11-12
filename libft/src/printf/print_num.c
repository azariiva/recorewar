/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:47 by fhilary           #+#    #+#             */
/*   Updated: 2020/07/06 02:57:15 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_integer.h"
#include "libft_string.h"

void		num_prec_zero(t_pf *pf)
{
	if ((pf->flag & PLUS_FLAG) || (pf->flag & SPACE_FLAG))
		pf->width--;
	if (!(pf->flag & MIN_FLAG) && pf->width > 0)
	{
		pf->len += ft_putcharn_buf(&(pf->buf), ' ', pf->width);
		pf->width = 0;
	}
	if (pf->flag & PLUS_FLAG)
		pf->len += ft_putchar_buf(&(pf->buf), '+');
	if (pf->flag & SPACE_FLAG)
		pf->len += ft_putchar_buf(&(pf->buf), ' ');
	if (pf->width > 0)
		ft_putcharn_buf(&(pf->buf), ' ', pf->width);
}

static void	print_zero_flag_space_plus_flag(t_pf *pf, char **tmp)
{
	if ((*tmp)[0] == '-')
	{
		pf->len += ft_putchar_buf(&(pf->buf), '-');
		(*tmp)++;
	}
	else if (pf->flag & PLUS_FLAG)
		pf->len += ft_putchar_buf(&(pf->buf), '+');
	else if (pf->flag & SPACE_FLAG)
		pf->len += ft_putchar_buf(&(pf->buf), ' ');
}

void		print_zero_flag_num(t_pf *pf, int diff, char *tmp)
{
	if (tmp[0] == '-')
		pf->width--;
	if (((pf->flag & PLUS_FLAG) || (pf->flag & SPACE_FLAG)) && tmp[0] != '-')
		diff--;
	if (pf->prec == -1 && pf->data_type != 'f' && pf->data_type != 'F')
		pf->prec = (int)ft_strlen(tmp);
	while (pf->prec > 0 && pf->width-- > pf->prec
			&& (pf->data_type != 'f' && pf->data_type != 'F') && diff-- > 0)
		pf->len += ft_putchar_buf(&(pf->buf), ' ');
	print_zero_flag_space_plus_flag(pf, &tmp);
	while (diff-- > 0)
		pf->len += ft_putchar_buf(&(pf->buf), '0');
	print_precision(pf, tmp);
	pf->len += ft_putstr_buf(&(pf->buf), tmp);
}

void		print_no_zero_flag_num(t_pf *pf, int diff, char *tmp)
{
	if (!(pf->flag & MIN_FLAG))
	{
		pf->len += ft_putcharn_buf(&(pf->buf), ' ', diff);
		diff = 0;
	}
	print_plus_space_flag(pf, tmp);
	if (tmp[0] == '-')
	{
		pf->len += ft_putchar_buf(&(pf->buf), '-');
		print_precision(pf, tmp);
		pf->len += ft_putstr_buf(&(pf->buf), tmp + 1);
	}
	else
	{
		print_precision(pf, tmp);
		pf->len += ft_putstr_buf(&(pf->buf), tmp);
	}
	pf->len += ft_putcharn_buf(&(pf->buf), ' ', diff);
}

int			print_num_d(t_pf *pf, long long num)
{
	int		diff;
	char	*tmp;

	if (!num && pf->prec == -1)
	{
		num_prec_zero(pf);
		return (1);
	}
	tmp = ft_lltoa(num);
	if (!tmp)
		return (-1);
	diff = calc_diff(pf, tmp);
	if (pf->flag & ZERO_FLAG)
		print_zero_flag_num(pf, diff, tmp);
	else
		print_no_zero_flag_num(pf, diff, tmp);
	ft_strdel(&tmp);
	return (0);
}
