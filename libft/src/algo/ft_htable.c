/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:57:49 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/03 17:52:11 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_algo.h"
#include "libft_memory.h"

void			ft_htdel(t_htable **ht, void (*del)(void *, size_t))
{
	size_t	i;

	if (ht)
	{
		if (*ht && (*ht)->body)
		{
			if (del)
			{
				i = -1;
				while (++i < (*ht)->size)
					ft_quedel((*ht)->body + i, del);
			}
			ft_memdel((void **)&((*ht)->body));
		}
		ft_memdel((void **)ht);
	}
}

t_htable		*ft_htnew(const size_t size,
int (*cmp)(const void *, const void *),
unsigned long (*hash)(const void *, const size_t))
{
	t_htable	*ht;

	if (!(ht = ft_memalloc(sizeof(*ht))))
		return (NULL);
	ht->size = size;
	if (!(ht->body = ft_memalloc(size * sizeof(*(ht->body)))))
	{
		ft_htdel(&ht, NULL);
		return (NULL);
	}
	ht->cmp = cmp;
	ht->hash = hash;
	return (ht);
}

int				ft_htadd(t_htable *ht, const void *tab,
const size_t sz)
{
	unsigned long	hash;

	if ((hash = ht->hash(tab, ht->size)) >= ht->size)
		return (FT_ERR);
	if (!ht->body[hash])
	{
		if (!(ht->body[hash] = ft_quenew(tab, sz)))
			return (FT_ERR);
	}
	else if (!ht->cmp(ht->body[hash], tab))
		return (FT_END);
	else if (ft_quevadd(ht->body[hash], tab, sz) == FT_ERR)
		return (FT_ERR);
	return (FT_OK);
}

void			*ft_htget(t_htable *ht, const void *tab)
{
	unsigned long	hash;
	t_list			*ptr;

	if ((hash = ht->hash(tab, ht->size)) >= ht->size)
		return (NULL);
	if (!ht->body[hash])
		return (NULL);
	ptr = ht->body[hash]->head;
	while (ptr)
	{
		if (!ht->cmp(ptr->content, tab))
			return (ptr->content);
		ptr = ptr->next;
	}
	return (NULL);
}
