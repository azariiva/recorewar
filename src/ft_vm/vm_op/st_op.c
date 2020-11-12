/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:47:29 by rnugroho          #+#    #+#             */
/*   Updated: 2020/11/12 20:14:17 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void	st_op(t_vm *vm, t_process *p)
{
	short	param1;
	char	*temp;

	if (p->op.params[0].value < 1 || p->op.params[0].value > 16 ||
		((p->op.params[1].type == REG_CODE) && (p->op.params[1].value < 1
			|| p->op.params[1].value > 16)))
	{
		op_include(vm, p);
		return ;
	}
	if (p->op.params[1].type == REG_CODE)
		p->reg[p->op.params[1].value] =
			p->reg[p->op.params[0].value];
	else
	{
		param1 = (p->offset + p->pc +
			((short)p->op.params[1].value % IDX_MOD)) % MEM_SIZE;
		(param1 < 0) ? param1 += MEM_SIZE : 0;
		temp = big_end_convert(p->reg[p->op.params[0].value], 4);
		st_mem(param1, temp, p->champ, 4);
	}
	op_include(vm, p);
}

void	vm_st_print(t_process p)
{
	if (p.op.params[0].value < 1 || p.op.params[0].value > 16 ||
		((p.op.params[1].type == REG_CODE) &&
			(p.op.params[1].value < 1 || p.op.params[1].value > 16)))
		return ;
	ft_printf("P %4d | ", p.index);
	ft_printf("%s", g_op_dict[p.op.opcode].name);
	ft_printf(" r%d", p.op.params[0].value);
	ft_printf(" %hd", p.op.params[1].value);
	ft_printf("\n");
}
