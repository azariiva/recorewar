/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:38:33 by rnugroho          #+#    #+#             */
/*   Updated: 2020/11/12 20:03:07 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

static void	vm_load_champs(t_vm *vm)
{
	int			i;
	t_process	p;

	i = -1;
	init_globals();
	vm->winner = vm->champ_size - 1;
	ft_bzero(&p, sizeof(t_process));
	vm->process_index = 1;
	fta_reserve(&(vm->processes), 3000000 * sizeof(t_process));
	(vm->dump != 3) ? ft_printf("Introducing contestants...\n") : 0;
	while (++i < vm->champ_size)
	{
		if (vm->dump != 3)
			ft_printf("* Player %d, weighing %d %s, \"%s\" (\"%s\") !\n", i + 1,
			vm->champ[i].header.prog_size, (vm->champ[i].header.prog_size > 1) ?
			"bytes" : "byte", vm->champ[i].header.prog_name,
			vm->champ[i].header.comment);
		st_mem(i * MEM_SIZE / vm->champ_size, vm->champ[i].op, i,
			vm->champ[i].header.prog_size);
		p.offset = i * MEM_SIZE / vm->champ_size;
		p.champ = i;
		p.index = vm->process_index++;
		p.reg[1] = (i + 1) * -1;
		fta_append(&(vm->processes), &p, 1);
	}
}

static int	vm_populate_players(int i, char **av, t_vm *vm)
{
	int j;

	j = 0;
	while (vm->players[j])
		j++;
	if (j < 4)
		vm->players[j] = av[i];
	else
		return (-1);
	return (0);
}

static int	vm_get_champions(char **av, t_vm *vm)
{
	int i;
	int j;
	int equ;
	int num;

	i = 0;
	num = 0;
	while (av[++i])
	{
		j = -1;
		equ = 0;
		if (ft_strequ(&av[i][ft_strlen(av[i]) - 4], ".cor"))
		{
			while (++j < 4)
				if (ft_strequ(av[i], vm->players[j]) && av[i] == vm->players[j])
					equ = 1;
			if (!equ && vm_populate_players(i, av, vm) == -1)
				num = MAX_PLAYERS + 1;
			num++;
		}
	}
	vm->champ_size = num;
	return ((num < 1 || num > MAX_PLAYERS) ? -1 : num);
}

int			main(int ac, char **av)
{
	t_vm			vm;
	time_t			start;
	static t_array	processes = NEW_ARRAY(t_process);

	ft_bzero(&vm, sizeof(t_vm));
	vm.processes = processes;
	if (ac < 2 || options(av, &vm) == -1)
		return (print_usage(av, -1));
	if (vm_get_champions(av, &vm) == -1)
		return (error(vm.champ_size < 1 ? CHAMP_MIN : CHAMP_MAX, -1, NULL));
	if (read_binaries(vm.players, &vm) == -1)
		return (-1);
	vm_load_champs(&vm);
	while (checker(&vm))
	{
		exec(&vm);
		if ((vm.dump && vm.cycles == g_cycles))
			break ;
	}
	(!vm.dump || g_cycles < vm.cycles) ?
	ft_printf("Contestant %d, \"%s\", has won !\n",
		vm.winner + 1, vm.champ[vm.winner].header.prog_name) : 0;
	free_funk(&vm);
	return (0);
}
