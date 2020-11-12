/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:25 by fhilary           #+#    #+#             */
/*   Updated: 2020/07/06 03:03:53 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void	print_num(t_pf *pf, va_list va)
{
	long long	n;

	if ((pf->mod & LL_MOD) || (pf->mod & J_MOD) || (pf->mod & Z_MOD))
		n = va_arg(va, long long);
	else if ((pf->mod & L_MOD) || pf->data_type == 'D')
		n = (long long)va_arg(va, long);
	else if (pf->mod & HH_MOD)
		n = (long long)((signed char)(va_arg(va, int)));
	else if (pf->mod & H_MOD)
		n = (long long)((short)(va_arg(va, int)));
	else
		n = (long long)va_arg(va, int);
	print_num_d(pf, n);
}

static void	print_decimal(t_pf *pf, va_list va)
{
	long double	n;

	if (!(pf->prec))
		pf->prec = 6;
	if (pf->mod & CAP_L_MOD)
		n = va_arg(va, long double);
	else if (pf->mod & L_MOD)
		n = (long double)(va_arg(va, double));
	else
		n = (long double)(va_arg(va, double));
	print_float(pf, n);
}

void		print_txt(t_pf *pf, va_list va)
{
	if (pf->data_type == 's')
		print_txt_s(pf, va_arg(va, char*));
	else if (pf->data_type == 'c')
		print_txt_c(pf, (char)(va_arg(va, int)));
	if (pf->data_type == '%')
		print_txt_c(pf, '%');
}

void		print_base(t_pf *pf, va_list va)
{
	int					base;
	unsigned long long	n;

	if (pf->data_type == 'o' || pf->data_type == 'O')
		base = 8;
	else if (pf->data_type == 'x' || pf->data_type == 'X'
	|| pf->data_type == 'p')
		base = 16;
	else
		base = 10;
	n = 0;
	if ((pf->mod & LL_MOD) || (pf->mod & J_MOD))
		n = va_arg(va, unsigned long long);
	else if ((pf->mod & L_MOD) || (pf->mod & Z_MOD) || pf->data_type == 'p'
	|| pf->data_type == 'O' || pf->data_type == 'U')
		n = va_arg(va, unsigned long);
	else if (pf->mod & HH_MOD)
		n = (unsigned char)va_arg(va, unsigned int);
	else if (pf->mod & H_MOD)
		n = (unsigned short)va_arg(va, unsigned int);
	else
		n = (unsigned long long)va_arg(va, unsigned int);
	print_b(pf, n, base);
}

void		print_placeholder(t_pf *pf, va_list va)
{
	if (pf->data_type == 'd' || pf->data_type == 'D'
			|| pf->data_type == 'i')
		print_num(pf, va);
	if (pf->data_type == 'f' || pf->data_type == 'F')
		print_decimal(pf, va);
	else if (pf->data_type == 'o' || pf->data_type == 'O'
				|| pf->data_type == 'u' || pf->data_type == 'U'
					|| pf->data_type == 'x' || pf->data_type == 'X'
						|| pf->data_type == 'p')
		print_base(pf, va);
	else if (pf->data_type == 's' || pf->data_type == 'S'
				|| pf->data_type == 'c' || pf->data_type == 'C'
					|| pf->data_type == '%')
		print_txt(pf, va);
}
