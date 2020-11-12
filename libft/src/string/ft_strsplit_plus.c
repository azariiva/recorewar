/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 20:53:14 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 19:54:20 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_memory.h"
#include <stddef.h>

static void		*ft_free_warr(char **warr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		ft_strdel(warr + i++);
	ft_memdel((void **)warr);
	return (NULL);
}

static size_t	ft_count_words(const char *s, int (*cmp)(int))
{
	size_t	ctr;

	ctr = 0;
	while (*s)
	{
		while (cmp(*s))
			++s;
		if (*s)
			++ctr;
		while (*s && !cmp(*s))
			++s;
	}
	return (ctr);
}

char			**ft_strsplit_plus(char const *s, int (*cmp)(int))
{
	char	**warr;
	char	**p_warr;
	size_t	len;

	if (!s || !(warr = (char **)ft_memalloc((ft_count_words(s, cmp) + 1) * \
	sizeof(char *))))
		return (NULL);
	p_warr = warr;
	while (*s)
	{
		while (cmp(*s))
			++s;
		if (*s)
		{
			len = 1;
			while (!cmp(s[len]) && s[len])
				++len;
			if (!(*p_warr = ft_strsub(s, 0, len)))
				return (ft_free_warr(warr, p_warr - warr));
			++p_warr;
			s += len;
		}
	}
	*p_warr = NULL;
	return (warr);
}
