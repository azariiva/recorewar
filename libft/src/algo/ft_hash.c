/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:45:13 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/17 18:58:49 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_algo.h"

unsigned long	ft_strhash(const void *tab, const size_t modulo)
{
	unsigned long			hash;
	unsigned				base;
	const unsigned char		*ptr;

	base = (1 << (sizeof(unsigned char) * 8));
	hash = 0;
	ptr = (const unsigned char *)tab;
	while (*ptr != '\0')
		hash = (hash * base + *ptr++) % modulo;
	return (hash);
}
