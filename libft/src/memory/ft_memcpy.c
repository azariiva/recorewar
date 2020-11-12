/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:16:45 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/30 13:26:45 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"
#include <stddef.h>

/*
** TODO: rewrite ft_memcpy to make it faster.
** P.S. Use ft_memset as a reference
*/

static inline void		assign(long int dptr, long int sptr)
{
	((ft_op *)dptr)[0] = ((ft_op *)sptr)[0];
	((ft_op *)dptr)[1] = ((ft_op *)sptr)[1];
	((ft_op *)dptr)[2] = ((ft_op *)sptr)[2];
	((ft_op *)dptr)[3] = ((ft_op *)sptr)[3];
	((ft_op *)dptr)[4] = ((ft_op *)sptr)[4];
	((ft_op *)dptr)[5] = ((ft_op *)sptr)[5];
	((ft_op *)dptr)[6] = ((ft_op *)sptr)[6];
	((ft_op *)dptr)[7] = ((ft_op *)sptr)[7];
}

static inline void		incptrs(long int *sptr, long int *dptr, size_t val)
{
	(*sptr) += val;
	(*dptr) += val;
}

static inline void		middle(long int *sptr, size_t *n, long int *dptr)
{
	size_t register	xlen;

	xlen = (*n) / (OPSIZ * 8);
	while (xlen > 0)
	{
		assign(*dptr, *sptr);
		incptrs(sptr, dptr, 8 * OPSIZ);
		xlen--;
	}
	(*n) %= (OPSIZ * 8);
	xlen = (*n) / OPSIZ;
	while (xlen > 0)
	{
		((ft_op *)(*dptr))[0] = ((ft_op *)(*sptr))[0];
		incptrs(sptr, dptr, OPSIZ);
		xlen--;
	}
	(*n) %= OPSIZ;
}

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	long int	dptr;
	long int	sptr;

	if (!(sptr = (long int)src) ||
	!(dptr = (long int)dst))
		return (NULL);
	if (n >= 8)
	{
		while (dptr % OPSIZ != 0)
		{
			((unsigned char *)dptr)[0] = ((unsigned char *)sptr)[0];
			incptrs(&sptr, &dptr, 1);
			n--;
		}
		middle(&sptr, &n, &dptr);
	}
	while (n-- > 0)
	{
		((unsigned char *)dptr)[0] = ((unsigned char *)sptr)[0];
		dptr++;
		sptr++;
	}
	return (dst);
}
