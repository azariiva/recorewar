/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:51:58 by rnugroho          #+#    #+#             */
/*   Updated: 2020/11/12 20:14:32 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void	zjmp_op(t_vm *vm, t_process *p)
{
	short		value;

	if (p->carry)
	{
		value = p->op.params[0].value;
		value = value % IDX_MOD;
		value += p->offset + p->pc;
		value = value % MEM_SIZE;
		p->pc = value - p->offset;
		if (value < 0)
			p->pc += MEM_SIZE;
	}
	else
		op_include(vm, p);
}

void	vm_zjmp_print(t_process p)
{
	short	value;

	value = (p.op.params[0].value);
	ft_printf("P %4d | ", p.index);
	ft_printf("%s", g_op_dict[p.op.opcode].name);
	ft_printf(" %hd", value);
	if (!p.carry)
		ft_printf(" FAILED");
	else
		ft_printf(" FT_OK");
	ft_printf("\n");
}
