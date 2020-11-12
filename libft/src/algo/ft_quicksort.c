/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:25:31 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/23 15:13:09 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_algo.h"

static void	sort(char*const tab, const size_t esz, const long long lower,
const long long upper, int (*cmp)(const void *, const void *))
{
	long long	i;
	long long	j;
	long long	p;

	i = lower;
	j = upper;
	p = lower;
	if (i >= j)
		return ;
	while (i < j)
	{
		while (i < upper && cmp(tab + i, tab + p) < 0)
			i += esz;
		while (cmp(tab + j, tab + p) > 0)
			j -= esz;
		if (i < j)
		{
			ft_swap(tab + i, tab + j, esz);
			i += esz;
			j -= esz;
		}
	}
	ft_swap(tab + p, tab + j, esz);
	sort(tab, esz, lower, j - esz, cmp);
	sort(tab, esz, j + esz, upper, cmp);
}

void		ft_quicksort(char*const tab, const size_t esz, const size_t sz,
int (*cmp)(const void *, const void *))
{
	sort(tab, esz, 0, (sz - 1) * esz, cmp);
	ft_swap(NULL, NULL, 0);
}
