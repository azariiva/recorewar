/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:32 by fhilary           #+#    #+#             */
/*   Updated: 2020/07/06 02:59:15 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_integer.h"
#include "libft_string.h"

static void	print_0x(t_pf *pf, char *tmp)
{
	if (pf->data_type == 'p')
		pf->len += ft_putstr_buf(&(pf->buf), "0x");
	else if ((pf->flag & HASH_FLAG) && tmp[0] != '0')
	{
		if (pf->data_type == 'x')
			pf->len += ft_putstr_buf(&(pf->buf), "0x");
		else if (pf->data_type == 'X')
			pf->len += ft_putstr_buf(&(pf->buf), "0X");
		else if ((pf->data_type == 'o'
			|| pf->data_type == 'O')
			&& (int)ft_strlen(tmp) >= pf->prec)
			pf->len += ft_putchar_buf(&(pf->buf), '0');
	}
}

static void	print_zero_flag_ull(t_pf *pf, int *diff, char *tmp)
{
	if (tmp[0] == '-')
	{
		ft_putchar_buf(&(pf->buf), '-');
		tmp++;
	}
	else
		pf->len--;
	pf->len++;
	print_0x(pf, tmp);
	pf->len += ft_putcharn_buf(&(pf->buf), '0', *diff);
	*diff = 0;
	pf->len += ft_putstr_buf(&(pf->buf), tmp);
}

static void	print_ull(t_pf *pf, int *diff, char *tmp)
{
	if (!(pf->flag & MIN_FLAG))
	{
		pf->len += ft_putcharn_buf(&(pf->buf), ' ', *diff);
		*diff = 0;
	}
	print_0x(pf, tmp);
	print_precision(pf, tmp);
	pf->len += ft_putstr_buf(&(pf->buf), tmp);
	pf->len += ft_putcharn_buf(&(pf->buf), ' ', *diff);
	*diff = 0;
}

int			print_b(t_pf *pf, unsigned long long num, int base)
{
	int		diff;
	char	*tmp;

	if (!num && pf->prec == -1 && !((pf->flag & HASH_FLAG) && \
				(pf->data_type == 'o' || pf->data_type == 'O')))
	{
		if (pf->data_type == 'p')
			pf->len += ft_putstr_buf(&(pf->buf), "0x");
		pf->len += pf->width;
		ft_putcharn_buf(&(pf->buf), ' ', pf->width);
		return (1);
	}
	if (!(tmp = ft_ulltoa_base(num, base)))
		return (-1);
	if (pf->data_type == 'X')
		ft_strup(tmp);
	diff = calc_diff(pf, tmp);
	if (pf->flag & ZERO_FLAG)
		print_zero_flag_ull(pf, &diff, tmp);
	else
		print_ull(pf, &diff, tmp);
	ft_strdel(&tmp);
	return (0);
}
