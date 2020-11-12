/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:41:09 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 20:04:53 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_integer.h"

char	*ft_itoa(int n)
{
	char		*s;
	size_t		len;
	int			tmp;

	len = (n <= 0);
	tmp = n;
	while (tmp)
	{
		++len;
		tmp /= 10;
	}
	if (!(s = ft_strnew(len)))
		return (0);
	tmp = len - 2;
	s[len - 1] = ft_abs(n % 10) + '0';
	if (n < 0)
		s[0] = '-';
	n = ft_abs(n / 10);
	while (n)
	{
		s[tmp--] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
