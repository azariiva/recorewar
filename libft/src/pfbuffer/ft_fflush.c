/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 02:09:49 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/06 03:22:53 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pfbuffer.h"
#include "libft_memory.h"
#include <unistd.h>

ssize_t		ft_fflush(t_buf *buf)
{
	ssize_t	res;

	res = write(buf->fd, buf->body, buf->total);
	ft_bzero(buf->body, MAX_BUF);
	buf->total = 0;
	return (res);
}
