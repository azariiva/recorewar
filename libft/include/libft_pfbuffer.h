/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_pfbuffer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 02:09:07 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/09 15:06:55 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PFBUFFER_H

# define LIBFT_PFBUFFER_H

# ifndef MAX_BUF
#  define MAX_BUF 64
# endif

# include <sys/types.h>

typedef struct	s_buf
{
	unsigned char	body[MAX_BUF];
	size_t			total;
	int				fd;
}				t_buf;

ssize_t			ft_putstr_buf(t_buf *buf, const char *str);
ssize_t			ft_putchar_buf(t_buf *buf, char c);
ssize_t			ft_fflush(t_buf *buf);
ssize_t			ft_putcharn_buf(t_buf *buf, char c, size_t n);
ssize_t			ft_putstrn_buf(t_buf *buf, const char *str, size_t n);

#endif
