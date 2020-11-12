/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:25:39 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/12 20:25:40 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

static int	vm_opt_n_2(int i, char **av, t_vm *vm)
{
	int num;

	if (!ft_strncmp(av[i], "-n", 2))
	{
		if (!isnumber(&av[i][2]))
			return (-1);
		num = ft_abs(ft_atoi(&av[i][2]));
		if (num < 1 || num > MAX_PLAYERS)
			return (-1);
		if (!av[i + 1] ||
			!ft_strequ(&av[i + 1][ft_strlen(av[i + 1]) - 4], ".cor"))
			return (-1);
		vm->players[num - 1] = av[i + 1];
	}
	return (0);
}

static int	vm_opt_n(int i, char **av, t_vm *vm)
{
	int num;

	num = 1;
	if (!ft_strcmp(av[i], "-n"))
	{
		if (!isnumber(av[i + 1]))
			return (-1);
		num = ft_abs(ft_atoi(av[i + 1]));
		if (num < 1 || num > MAX_PLAYERS)
			return (-1);
		if (!av[i + 2] ||
			!ft_strequ(&av[i + 2][ft_strlen(av[i + 2]) - 4], ".cor"))
			return (-1);
		vm->players[num - 1] = av[i + 2];
	}
	else if (vm_opt_n_2(i, av, vm) == -1)
		return (-1);
	return (0);
}

static int	vm_opt_v_2(int i, char **av, t_vm *vm)
{
	int lvl;

	if (!ft_strncmp(av[i], "-v", 2))
	{
		if (!isnumber(&av[i][2]))
			return (-1);
		lvl = ft_atoi(&av[i][2]);
		if (!check_val_verb(lvl))
			return (-1);
		set_v(lvl, vm);
	}
	return (0);
}

static int	vm_opt_v(int i, char **av, t_vm *vm)
{
	int lvl;

	if (!ft_strcmp(av[i], "-v"))
	{
		if (!isnumber(av[i + 1]))
			return (-1);
		lvl = ft_atoi(av[i + 1]);
		if (!check_val_verb(lvl))
			return (-1);
		set_v(lvl, vm);
	}
	else if (vm_opt_v_2(i, av, vm) == -1)
		return (-1);
	return (0);
}

int			options(char **av, t_vm *vm)
{
	int i;

	i = 0;
	while (av[++i])
	{
		if (!check_valid_arg(av[i], vm))
			return (-1);
		if (!ft_strcmp(av[i], "-dump"))
		{
			if (!isnumber(av[i + 1]) ||
				((vm->cycles = ft_atoi(av[i + 1])) <= 0))
				return (-1);
			vm->dump = (!ft_strcmp(av[i], "-dump")) ? 1 : 2;
		}
		else if ((vm_opt_v(i, av, vm) == -1) || (vm_opt_n(i, av, vm) == -1))
			return (-1);
	}
	return (0);
}
