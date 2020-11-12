/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:10 by fhilary           #+#    #+#             */
/*   Updated: 2020/07/06 02:59:56 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_integer.h"
#include "libft_ctype.h"

static void	set_flag(t_pf *pf, char c, int *i)
{
	if (c == '-')
		pf->flag |= MIN_FLAG;
	else if (c == '+')
		pf->flag |= PLUS_FLAG;
	else if (c == ' ')
		pf->flag |= SPACE_FLAG;
	else if (c == '0')
		pf->flag |= ZERO_FLAG;
	else if (c == '#')
		pf->flag |= HASH_FLAG;
	(*i)++;
}

static void	set_width(t_pf *pf, const char *fmt, va_list va, int *i)
{
	long	w;

	if (fmt[*i] == '*')
	{
		w = (long)va_arg(va, int);
		if (w < 0)
		{
			w *= -1;
			pf->flag |= MIN_FLAG;
		}
		pf->width = (int)w;
		(*i)++;
	}
	else
	{
		pf->width = ft_atoi(&fmt[*i]);
		while (fmt[*i] >= '0' && fmt[*i] <= '9')
			(*i)++;
	}
}

static void	set_precision(t_pf *pf, const char *fmt, va_list va, int *i)
{
	int	w;

	if (fmt[++(*i)] == '*')
	{
		if ((w = va_arg(va, int)) >= 0)
		{
			pf->prec = w;
			if (pf->prec == 0)
				pf->prec = -1;
		}
		(*i)++;
	}
	else
	{
		pf->prec = ft_atoi(fmt + *i);
		if (pf->prec <= 0)
			pf->prec = -1;
	}
	while (ft_isdigit(fmt[*i]))
		(*i)++;
}

static void	set_modifier(t_pf *pf, const char *fmt, int *i)
{
	if (fmt[*i] == 'l')
		pf->mod |= (fmt[(*i) + 1] == 'l' ? LL_MOD : L_MOD);
	if (fmt[*i] == 'h')
		pf->mod |= (fmt[(*i) + 1] == 'h' ? HH_MOD : H_MOD);
	if (fmt[*i] == 'L')
		pf->mod |= CAP_L_MOD;
	if (fmt[*i] == 'j')
		pf->mod |= J_MOD;
	if (fmt[*i] == 'z')
		pf->mod |= Z_MOD;
	(*i)++;
}

void		parse_placeholder(t_pf *pf, const char *fmt, va_list va, int *i)
{
	(*i)++;
	while (!(pf->data_type))
	{
		if (is_flag(fmt[*i]))
			set_flag(pf, fmt[*i], i);
		else if ((fmt[*i] >= '1' && fmt[*i] <= '9') || fmt[*i] == '*')
			set_width(pf, fmt, va, i);
		else if (fmt[*i] == '.')
			set_precision(pf, fmt, va, i);
		else if (is_modifier(fmt[*i]))
			set_modifier(pf, fmt, i);
		else if (is_data_type(fmt[*i]))
		{
			pf->data_type = fmt[*i];
			validate_flags(pf);
		}
		else
			if_nothing(pf, fmt, i);
	}
}
