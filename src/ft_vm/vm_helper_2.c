/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_helper_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:28:03 by fpetras           #+#    #+#             */
/*   Updated: 2020/11/12 18:46:28 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void	init_globals(void)
{
	g_cycles = 0;
	g_cycles_to = 0;
	g_cycles_to_die = CYCLE_TO_DIE;
	g_live_nbr = 0;
	ft_bzero(&g_memory, MEM_SIZE);
	ft_bzero(&g_memory_mark, MEM_SIZE);
}

char		*big_end_convert(int value, int size)
{
	int			i;
	int			bits;
	static char	res[4];

	ft_bzero(res, sizeof(res));
	i = 0;
	bits = size * 8 - 8;
	while (i < size)
	{
		res[i] = value >> (bits - i * 8);
		i++;
	}
	return (res);
}

void	st_mem(int index, char *value, int champ, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (index == MEM_SIZE)
			index = 0;
		g_memory[index] = value[i];
		g_memory_mark[index] = champ + 1;
		index++;
		i++;
	}
}

int		ldd_memory(int index, int size)
{
	int		i;
	int		result;
	int		max;

	i = 1;
	result = 0;
	max = 0;
	while (i <= size)
	{
		if (index == MEM_SIZE)
			index = 0;
		result += g_memory[index] << ((size - i) * 8);
		max += 0xff << ((i - 1) * 8);
		i++;
		index++;
	}
	if (result > max / 2 + 1)
		result = result - (max + 1);
	return (result);
}

int		ld_funk(int index, int size, char *op)
{
	int		i;
	int		result;

	i = 1;
	result = 0;
	while (i <= size)
	{
		if (index == MEM_SIZE)
			index = 0;
		result += op[index] << ((size - i) * 8);
		i++;
		index++;
	}
	return (result);
}
