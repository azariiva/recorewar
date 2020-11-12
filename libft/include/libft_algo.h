/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_algo.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:11:02 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/03 17:29:06 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ALGO_H

# define LIBFT_ALGO_H

# include "libft_queue.h"
# include <sys/types.h>
# include <stddef.h>

/*
** ft_swap swaps elements of any type
*/
void			ft_swap(void *a, void *b, size_t esz);

# define FT_SWAP(a, b) (ft_swap((void *)&a, (void *)&b, sizeof(a)))

/*
** > tab is array of any type
** > esz is size of element of array
** > sz is actual size of array in elements
** > cmp is comparator, that returns numbers greater than 0 if a > b or numbers
** less than 0 if a < b or 0 if a == b
*/
void			ft_quicksort(char*const tab, const size_t esz, const size_t sz,
int (*cmp)(const void *, const void *));

# define FT_QUICKSORT(tab, sz, cmp) (ft_quicksort((char *)tab, sizeof(*tab), sz, cmp))

/*
** I've used this reference shorturl.at/adkmw
** HashTable will be chained.
** In HashFunction I'll use Division method
*/
unsigned long	ft_strhash(const void *tab, const size_t modulo);

typedef struct	s_htable
{
	size_t			size;
	t_queue			**body;
	int				(*cmp)(const void *, const void *);
	unsigned long	(*hash)(const void *, const size_t);
}				t_htable;

t_htable		*ft_htnew(const size_t size,
int (*cmp)(const void *, const void *),
unsigned long (*hash)(const void *, const size_t));

void			ft_htdel(t_htable **ht, void (*del)(void *, size_t));
/*
** > returns FT_ERR on internal error
** > returns FT_END if tab is already in the table
*/
int				ft_htadd(t_htable *ht, const void *tab,
const size_t sz);
void			*ft_htget(t_htable *ht, const void *tab);

#endif
