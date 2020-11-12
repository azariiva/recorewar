/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:17 by fhilary           #+#    #+#             */
/*   Updated: 2020/07/06 02:25:02 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	if_nothing(t_pf *pf, const char *fmt, int *i)
{
	if (fmt[*i])
	{
		pf->data_type = 'c';
		validate_flags(pf);
	}
	pf->data_type = -1;
}

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' '
	|| c == '0' || c == '#')
		return (1);
	return (0);
}

int		is_modifier(char c)
{
	if (c == 'l' || c == 'h' || c == 'L'
	|| c == 'j' || c == 'z')
		return (1);
	return (0);
}

int		is_data_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
	|| c == 'd' || c == 'i' || c == 'o' || c == 'u'
	|| c == 'x' || c == 'X' || c == 'f' || c == '%'
	|| c == 'D' || c == 'O' || c == 'U' || c == 'F'
	|| c == 'C' || c == 'S')
		return (1);
	return (0);
}

void	validate_flags(t_pf *pf)
{
	if ((pf->flag & PLUS_FLAG) && (pf->flag & SPACE_FLAG))
		pf->flag &= ~SPACE_FLAG;
	if ((pf->flag & MIN_FLAG) && (pf->flag & ZERO_FLAG))
		pf->flag &= ~ZERO_FLAG;
	if (pf->prec != 0 && (pf->flag & ZERO_FLAG)
		&& (pf->data_type == 'd' || pf->data_type == 'i'
		|| pf->data_type == 'o' || pf->data_type == 'O'
		|| pf->data_type == 'u' || pf->data_type == 'U'
		|| pf->data_type == 'x' || pf->data_type == 'X'))
		pf->flag &= ~ZERO_FLAG;
}
