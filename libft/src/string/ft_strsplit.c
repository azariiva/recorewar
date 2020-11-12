/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:17 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/06 02:52:30 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_memory.h"
#include <stdlib.h>

static void		*ft_free_warr(char **warr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		ft_strdel(warr + i++);
	ft_memdel((void **)&warr);
	return (NULL);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	ctr;

	ctr = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++ctr;
		while (*s && *s != c)
			++s;
	}
	return (ctr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**warr;
	char	**p_warr;
	size_t	len;

	if (!s || !(warr = (char **)ft_memalloc((ft_count_words(s, c) + 1) * \
					sizeof(char *))))
		return (NULL);
	p_warr = warr;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
		{
			len = 1;
			while (s[len] != c && s[len])
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
