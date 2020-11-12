/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:39:38 by fhilary           #+#    #+#             */
/*   Updated: 2020/07/06 02:55:53 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_float.h"
#include "libft_string.h"
#include <stdbool.h>
#include <float.h>

static int	is_inf(long double n, char **tmp)
{
	bool	ret_1;

	ret_1 = false;
	if (n != n)
	{
		*tmp = ft_strdup("nan");
		ret_1 = true;
	}
	else if (n < -FLT_MAX)
	{
		*tmp = ft_strdup("-inf");
		ret_1 = true;
	}
	else if (n > FLT_MAX)
	{
		*tmp = ft_strdup("inf");
		ret_1 = true;
	}
	if (ret_1 == true && !(*tmp))
		return (-1);
	if (ret_1 == true)
		return (1);
	return (0);
}

static int	is_neg_zero(t_pf *pf, long double n, char **tmp)
{
	char	*tmp_2;

	if (n == 0 && 1 / n < -FLT_MAX)
	{
		tmp_2 = ft_lftoa(n, pf->prec);
		if (!tmp_2)
			return (-1);
		*tmp = ft_strjoin("-", tmp_2);
		ft_strdel(&tmp_2);
		return (1);
	}
	return (0);
}

static void	add_dot(char **tmp)
{
	char	*tmp2;

	tmp2 = ft_strjoin(*tmp, ".");
	ft_strdel(tmp);
	*tmp = tmp2;
}

int			print_float(t_pf *pf, long double num)
{
	int		diff;
	char	*tmp;

	if (is_inf(num, &tmp))
	{
		if (pf->data_type == 'F')
			ft_strup(tmp);
		pf->flag &= ~ZERO_FLAG;
		pf->prec = 0;
		print_txt_s(pf, tmp);
		ft_strdel(&tmp);
		return (1);
	}
	if (!is_neg_zero(pf, num, &tmp))
		tmp = ft_lftoa(num, pf->prec);
	if (ft_strchr(tmp, '.') && pf->flag & HASH_FLAG)
		add_dot(&tmp);
	if (!tmp)
		return (-1);
	diff = calc_diff(pf, tmp);
	(pf->flag & ZERO_FLAG ? print_zero_flag_num(pf, diff, tmp) : \
								print_no_zero_flag_num(pf, diff, tmp));
	ft_strdel(&tmp);
	return (0);
}
