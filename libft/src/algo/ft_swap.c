/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:31:29 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/16 20:16:36 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_algo.h"
#include "libft_memory.h"

void	ft_swap(void *a, void *b, size_t esz)
{
	static void		*tmp;
	static size_t	oesz;

	if (esz == 0 && tmp)
	{
		ft_memdel(&tmp);
		return ;
	}
	if (oesz != esz)
	{
		oesz = esz;
		if (tmp)
			ft_memdel(&tmp);
		tmp = ft_memalloc(esz);
	}
	ft_memcpy(tmp, a, esz);
	ft_memcpy(a, b, esz);
	ft_memcpy(b, tmp, esz);
}
