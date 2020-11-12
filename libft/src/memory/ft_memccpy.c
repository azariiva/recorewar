/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:38:59 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 18:39:43 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dst) = ((char *)src)[i];
		dst = (char *)dst + 1;
		if (((unsigned char *)src)[i++] == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}
