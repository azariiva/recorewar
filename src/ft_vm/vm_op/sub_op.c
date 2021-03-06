/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:49:11 by rnugroho          #+#    #+#             */
/*   Updated: 2020/11/12 20:14:23 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void	sub_op(t_vm *vm, t_process *p)
{
	if (p->op.params[0].value < 1 ||
		p->op.params[0].value > 16 ||
		p->op.params[1].value < 1 ||
		p->op.params[1].value > 16 ||
		p->op.params[2].value < 1 ||
		p->op.params[2].value > 16)
	{
		op_include(vm, p);
		return ;
	}
	p->reg[p->op.params[2].value] =
		p->reg[p->op.params[0].value] -
		p->reg[p->op.params[1].value];
	if (p->reg[p->op.params[2].value] == 0)
		p->carry = 1;
	else
		p->carry = 0;
	op_include(vm, p);
}

void	vm_sub_print(t_process p)
{
	if (p.op.params[0].value < 1 ||
		p.op.params[0].value > 16 ||
		p.op.params[1].value < 1 ||
		p.op.params[1].value > 16 ||
		p.op.params[2].value < 1 ||
		p.op.params[2].value > 16)
		return ;
	ft_printf("P %4d | ", p.index);
	ft_printf("%s", g_op_dict[p.op.opcode].name);
	ft_printf(" r%d", p.op.params[0].value);
	ft_printf(" r%d", p.op.params[1].value);
	ft_printf(" r%d", p.op.params[2].value);
	ft_printf("\n");
}
