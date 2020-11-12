/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:58:40 by rnugroho          #+#    #+#             */
/*   Updated: 2020/11/12 20:14:04 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void	lld_op(t_vm *vm, t_process *p)
{
	int		param0;

	if (p->op.params[1].value < 1 || p->op.params[1].value > 16)
	{
		op_include(vm, p);
		return ;
	}
	param0 = (p->op.params[0].type == IND_CODE) ?
		ldd_memory((p->offset + p->pc + p->op.params[0].value) % MEM_SIZE, 2)
		: p->op.params[0].value;
	p->reg[p->op.params[1].value] = (p->op.params[0].type == IND_CODE)
	? (short)param0 : param0;
	if (param0 == 0)
		p->carry = 1;
	else
		p->carry = 0;
	op_include(vm, p);
}

void	vm_lld_print(t_process p)
{
	int		param0;

	if (p.op.params[1].value < 1 || p.op.params[1].value > 16)
		return ;
	param0 = (p.op.params[0].type == IND_CODE) ?
		ldd_memory((p.offset + p.pc + p.op.params[0].value) % MEM_SIZE, 2)
		: p.op.params[0].value;
	ft_printf("P %4d | ", p.index);
	ft_printf("%s", g_op_dict[p.op.opcode].name);
	(p.op.params[0].type == IND_CODE) ?
	ft_printf(" %hd", param0) : ft_printf(" %d", param0);
	ft_printf(" r%d", p.op.params[1].value);
	ft_printf("\n");
}
