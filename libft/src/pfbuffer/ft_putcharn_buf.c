/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn_buf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 02:15:41 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/06 02:16:06 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pfbuffer.h"

ssize_t		ft_putcharn_buf(t_buf *buf, char c, size_t n)
{
	ssize_t	res;

	res = 0;
	while (n-- > 0)
	{
		buf->body[buf->total++] = c;
		++res;
		if (buf->total == MAX_BUF && ft_fflush(buf) < 0)
			res = 0;
	}
	return (res);
}
