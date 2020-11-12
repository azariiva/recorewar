/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 02:16:44 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/06 02:17:06 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pfbuffer.h"
#include "libft_string.h"

ssize_t		ft_putstrn_buf(t_buf *buf, const char *str, size_t n)
{
	size_t	i;
	ssize_t	res;

	res = 0;
	i = 0;
	if (ft_strlen(str) > n)
		while (i < n)
		{
			buf->body[buf->total++] = str[i];
			++i;
			++res;
			if (buf->total == MAX_BUF && ft_fflush(buf) < 0)
				res = 0;
		}
	else
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
