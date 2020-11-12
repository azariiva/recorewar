/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:16:48 by fhilary           #+#    #+#             */
/*   Updated: 2020/08/03 15:23:41 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_memccmp(const void *haystack, const void *needle, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n && ((unsigned char *)haystack)[i] != c)
	{
		if (((unsigned char *)haystack)[i] != ((unsigned char *)needle)[i])
			return (((unsigned char *)haystack)[i] -
			((unsigned char *)needle)[i]);
	}
	return (0);
}
