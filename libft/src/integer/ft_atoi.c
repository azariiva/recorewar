/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:21:24 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 18:33:21 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctype.h"

int		ft_atoi(char const *str)
{
	int					sign;
	unsigned long long	result;

	sign = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
	{
		sign = 1;
		++str;
	}
	else if (*str == '+')
		++str;
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (int)*str++ - '0';
		if (result > 9223372036854775807)
			return (!sign ? -1 : 0);
	}
	return (sign ? -result : result);
}
