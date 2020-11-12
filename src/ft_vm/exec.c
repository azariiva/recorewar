/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:28:36 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/12 20:28:37 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

static void	vm_print_v_4(t_process p)
{
	if (p.op.opcode != 0)
		(((void (*)())g_op_dict[p.op.opcode].opprint)(p));
}

static void	vm_print_v_16(t_process p)
{
	int i;
	int	size;

	if (p.op.opcode != 0 && (p.op.opcode != 9 || !p.carry))
	{
		ft_printf("ADV %d (0x%04x -> 0x%04x) ",
			p.pc_next - p.pc,
			p.offset + p.pc,
			p.offset + p.pc_next);
		i = p.offset + p.pc;
		size = 0;
		while (size < p.pc_next - p.pc)
		{
			if (i == MEM_SIZE)
				i = 0;
			ft_printf("%02x ", g_memory[i]);
			i++;
			size++;
		}
		ft_printf("\n");
	}
}

static void	vm_executor_op(t_vm *vm, t_process *p)
{
	t_process prev_p;

	decomp_param(p, &(p->op));
	p->pc_next = p->pc + p->op.size;
	ft_memcpy(&prev_p, p, sizeof(t_process));
	if (param_check(p->op) == -1)
		op_include(vm, p);
	else
	{
		(vm->option_v[V_LVL_4]) ? vm_print_v_4(*p) : 0;
		(((void (*)())g_op_dict[p->op.opcode].opfunc)(vm, p));
	}
	(vm->option_v[V_LVL_16]) ? vm_print_v_16(prev_p) : 0;
	ft_bzero(&(p->op), sizeof(t_op));
}

void		exec(t_vm *vm)
{
	int			i;
	t_process	*p;

	g_cycles++;
	g_cycles_to++;
	(vm->option_v[V_LVL_2]) ? ft_printf("It is now cycle %d\n", g_cycles) : 0;
	i = (int)(vm->processes.size) - 1;
	while (i >= 0)
	{
		p = &(((t_process*)vm->processes.data)[i]);
		if (p->op.opcode == 0)
			decomp_op(vm, p);
		if (p->cycles == g_cycles)
		{
			vm_executor_op(vm, p);
			(((t_process*)vm->processes.data)[i]) = *p;
		}
		i--;
	}
}
