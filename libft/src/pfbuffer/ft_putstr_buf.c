/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 02:12:58 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/06 02:14:14 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pfbuffer.h"

ssize_t		ft_putstr_buf(t_buf *buf, const char *str)
{
	ssize_t	res;

	res = 0;
	while (*str)
	{
		buf->body[buf->total++] = *str;
		++str;
		++res;
		if (buf->total == MAX_BUF && ft_fflush(buf) < 0)
			res = 0;
	}
	return (res);
}
