/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:50:00 by rnugroho          #+#    #+#             */
/*   Updated: 2020/11/12 20:13:34 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void	and_op(t_vm *vm, t_process *p)
{
	int		param0;
	int		param1;

	if (p->op.params[2].value < 1 || p->op.params[2].value > 16 ||
	((p->op.params[1].type == REG_CODE) && (p->op.params[1].value < 1 ||
	p->op.params[1].value > 16)) || ((p->op.params[0].type == REG_CODE) &&
	(p->op.params[0].value < 1 || p->op.params[0].value > 16)))
	{
		op_include(vm, p);
		return ;
	}
	param0 = (p->op.params[0].type == REG_CODE) ?
		p->reg[p->op.params[0].value] : p->op.params[0].value;
	param1 = (p->op.params[1].type == REG_CODE) ?
		p->reg[p->op.params[1].value] : p->op.params[1].value;
	param0 = (p->op.params[0].type == IND_CODE) ?
		ldd_memory((p->offset + p->pc +
		(p->op.params[0].value % IDX_MOD)) % MEM_SIZE, 4) : param0;
	param1 = (p->op.params[1].type == IND_CODE) ?
		ldd_memory((p->offset + p->pc +
		(p->op.params[1].value % IDX_MOD)) % MEM_SIZE, 4) : param1;
	p->reg[p->op.params[2].value] = param0 & param1;
	p->carry = (p->reg[p->op.params[2].value] == 0) ? 1 : 0;
	op_include(vm, p);
}

void	vm_and_print(t_process p)
{
	if (p.op.params[2].value < 1 || p.op.params[2].value > 16 ||
		((p.op.params[1].type == REG_CODE) &&
			(p.op.params[1].value < 1 || p.op.params[1].value > 16)) ||
		((p.op.params[0].type == REG_CODE) &&
			(p.op.params[0].value < 1 || p.op.params[0].value > 16)))
		return ;
	ft_printf("P %4d | ", p.index);
	ft_printf("%s", g_op_dict[p.op.opcode].name);
	if (p.op.params[0].type == REG_CODE)
		ft_printf(" %d", p.reg[p.op.params[0].value]);
	else if (p.op.params[0].type == IND_CODE)
		ft_printf(" %d", ldd_memory((p.offset +
			p.pc + (p.op.params[0].value % IDX_MOD)) % MEM_SIZE, 4));
	else
		ft_printf(" %d", p.op.params[0].value);
	if (p.op.params[1].type == REG_CODE)
		ft_printf(" %d", p.reg[p.op.params[1].value]);
	else if (p.op.params[1].type == IND_CODE)
		ft_printf(" %d", ldd_memory((p.offset + p.pc
			+ (p.op.params[1].value % IDX_MOD)) % MEM_SIZE, 4));
	else
		ft_printf(" %d", p.op.params[1].value);
	ft_printf(" r%d", p.op.params[2].value);
	ft_printf("\n");
}
