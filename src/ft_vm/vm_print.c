/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:41:04 by rnugroho          #+#    #+#             */
/*   Updated: 2020/11/12 20:17:17 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

int			print_usage(char **av, int status)
{
	ft_printf_fd(2, "usage: %s [options] [-n number] champion1.cor ...\n", av[0]);
	ft_printf_fd(2, "\n\033[1;37mOPTIONS\033[0m\n", 9);
	ft_printf_fd(2, "       -dump  nbr_cycles  : ");
	ft_printf_fd(2, "Dump the memory after nbr_cycles\n");
	ft_printf_fd(2, "       -v N : ");
	ft_printf_fd(2, "Verbosity levels, can be added together to enable several");
	ft_printf_fd(2, "\n                - 2  : Show cycles\n");
	ft_printf_fd(2, "                - 4  : Show operations\n");
	ft_printf_fd(2, "                - 8  : Show deaths\n");
	ft_printf_fd(2, "                - 16 : Show PC movements ");
	ft_printf_fd(2, "(Except for jumps)\n");
	return (status);
}

static int	vm_get_cursor_color(t_vm vm, int index)
{
	int		k;

	k = 0;
	while (k < (int)(vm.processes.size))
	{
		if (((t_process*)vm.processes.data)[k].offset +
			((t_process*)vm.processes.data)[k].pc == index)
			return (((t_process*)vm.processes.data)[k].champ + 1);
		k++;
	}
	return (0);
}
