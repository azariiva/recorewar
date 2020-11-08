/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:57:27 by rnugroho          #+#    #+#             */
/*   Updated: 2018/05/05 02:17:42 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void	vm_op_fork(t_vm *vm, t_process *p)
{
	t_process	new_p;
	short		value;

	ft_bzero(&new_p, sizeof(t_process));
	new_p.offset = p->champ * MEM_SIZE / vm->champ_size;
	new_p.champ = p->champ;
	new_p.live_nbr = p->live_nbr;
	new_p.live_cycle = p->live_cycle;
	new_p.carry = p->carry;
	ft_memcpy(&(new_p.reg), &(p->reg), sizeof(int) * (REG_NUMBER + 1));
	value = p->op.params[0].value;
	value = value % IDX_MOD;
	value += p->offset + p->pc;
	value = value % MEM_SIZE;
	new_p.pc = value - p->offset;
	if (value < 0)
		new_p.pc += MEM_SIZE;
	new_p.index = vm->process_index++;
	fta_append(&(vm->processes), &new_p, 1);
	vm_op_inc(vm, p);
}

void	vm_fork_print(t_process p)
{
	short value;

	ft_printf("P %4d | ", p.index);
	ft_printf("%s", g_op_dict[p.op.opcode].name);
	value = p.op.params[0].value;
	value = value % IDX_MOD;
	value += p.offset + p.pc;
	ft_printf(" %hd (%hd)", p.op.params[0].value,
		value);
	ft_printf("\n");
}
