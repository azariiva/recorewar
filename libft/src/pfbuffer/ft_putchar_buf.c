/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 02:14:55 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/06 02:15:12 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pfbuffer.h"

ssize_t		ft_putchar_buf(t_buf *buf, char c)
{
	buf->body[buf->total++] = c;
	if (buf->total == MAX_BUF && ft_fflush(buf) < 0)
		return (0);
	return (1);
}
