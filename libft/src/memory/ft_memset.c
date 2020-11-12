/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:16:41 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/12 20:42:26 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"
#include <stddef.h>

static inline void	assign(long int bp, ft_op cccc)
{
	((ft_op *)bp)[0] = cccc;
	((ft_op *)bp)[1] = cccc;
	((ft_op *)bp)[2] = cccc;
	((ft_op *)bp)[3] = cccc;
	((ft_op *)bp)[4] = cccc;
	((ft_op *)bp)[5] = cccc;
	((ft_op *)bp)[6] = cccc;
	((ft_op *)bp)[7] = cccc;
}

static ft_op		init_cccc(int c)
{
	ft_op	cccc;

	cccc = (unsigned char)c;
	cccc |= cccc << 8;
	cccc |= cccc << 16;
	if (OPSIZ > 4)
		cccc |= (cccc << 16) << 16;
	return (cccc);
}

static inline void	middle(ft_op cccc, size_t *len, long int *bp)
{
	size_t register	xlen;

	xlen = (*len) / (OPSIZ * 8);
	while (xlen > 0)
	{
		assign(*bp, cccc);
		(*bp) += 8 * OPSIZ;
		xlen--;
	}
	(*len) %= (OPSIZ * 8);
	xlen = (*len) / OPSIZ;
	while (xlen > 0)
	{
		((ft_op *)(*bp))[0] = cccc;
		(*bp) += OPSIZ;
		xlen--;
	}
	(*len) %= OPSIZ;
}

void				*ft_memset(void *b, int c, size_t len)
{
	long int		bp;

	if (!(bp = (long int)b))
		return (NULL);
	if (len >= 8)
	{
		while (bp % OPSIZ != 0)
		{
			((unsigned char *)bp)[0] = c;
			bp++;
			len--;
		}
		middle(init_cccc(c), &len, &bp);
	}
	while (len-- > 0)
	{
		((unsigned char *)bp)[0] = c;
		bp++;
	}
	return (b);
}
