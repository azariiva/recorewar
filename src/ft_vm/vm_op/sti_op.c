/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:56:40 by rnugroho          #+#    #+#             */
/*   Updated: 2020/11/12 20:14:21 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		sti_op(t_vm *vm, t_process *p)
{
	int			param1;
	int			param2;
	int			cursor;
	char		*temp;

	if (p->op.params[0].value < 1 || p->op.params[0].value > 16 ||
		((p->op.params[1].type == REG_CODE) &&
			(p->op.params[1].value < 1 || p->op.params[1].value > 16)) ||
		((p->op.params[2].type == REG_CODE) &&
			(p->op.params[2].value < 1 || p->op.params[2].value > 16)) ||
		p->op.params[1].type == 0 || p->op.params[2].type == 0)
	{
		op_include(vm, p);
		return ;
	}
	param1 = init_p(p, 1);
	param2 = (p->op.params[2].type == REG_CODE) ?
		p->reg[p->op.params[2].value] : p->op.params[2].value;
	cursor = cursor_(p, param1, param2, 1) % MEM_SIZE;
	(cursor < 0) ? cursor += MEM_SIZE : 0;
	temp = big_end_convert(p->reg[p->op.params[0].value], 4);
	st_mem(cursor, temp, p->champ, 4);
	op_include(vm, p);
}

static void	vm_sti_print_2(t_process p, int param1, int param2)
{
	ft_printf("P %4d | ", p.index);
	ft_printf("%s", g_op_dict[p.op.opcode].name);
	ft_printf(" r%d", p.op.params[0].value);
	(p.op.params[1].type == DIR_CODE) ?
	ft_printf(" %hd", param1) : ft_printf(" %d", param1);
	(p.op.params[2].type == DIR_CODE) ?
	ft_printf(" %hd\n", param2) : ft_printf(" %d\n", param2);
	if (p.op.params[1].type == DIR_CODE && p.op.params[2].type == DIR_CODE)
		ft_printf("       | -> store to %hd + %hd = %d (with pc and mod %d)",
		param1, param2, (short)param1 + (short)param2,
		p.offset + p.pc + ((short)param1 + (short)param2) % IDX_MOD);
	else if (p.op.params[1].type == DIR_CODE)
		ft_printf("       | -> store to %hd + %d = %d (with pc and mod %d)",
		param1, param2, (short)param1 + param2,
		p.offset + p.pc + ((short)param1 + param2) % IDX_MOD);
	else if (p.op.params[2].type == DIR_CODE)
		ft_printf("       | -> store to %d + %hd = %d (with pc and mod %d)",
		param1, param2, param1 + (short)param2,
		p.offset + p.pc + (param1 + (short)param2) % IDX_MOD);
	else
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)",
		param1, param2, param1 + param2,
		p.offset + p.pc + (param1 + param2) % IDX_MOD);
	ft_printf("\n");
}

void		vm_sti_print(t_process p)
{
	int param1;
	int param2;

	if (p.op.params[0].value < 1 || p.op.params[0].value > 16 ||
		((p.op.params[1].type == REG_CODE) &&
			(p.op.params[1].value < 1 || p.op.params[1].value > 16)) ||
		((p.op.params[2].type == REG_CODE) &&
			(p.op.params[2].value < 1 || p.op.params[2].value > 16)) ||
		p.op.params[1].type == 0 || p.op.params[2].type == 0)
		return ;
	param1 = (p.op.params[1].type == REG_CODE) ?
		p.reg[p.op.params[1].value] : p.op.params[1].value;
	param2 = (p.op.params[2].type == REG_CODE) ?
		p.reg[p.op.params[2].value] : p.op.params[2].value;
	param1 = (p.op.params[1].type == IND_CODE) ?
		ldd_memory((p.offset + p.pc +
			(p.op.params[1].value % IDX_MOD)) % MEM_SIZE, 4) : param1;
	vm_sti_print_2(p, param1, param2);
}
