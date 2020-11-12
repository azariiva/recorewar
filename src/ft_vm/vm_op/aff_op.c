/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:01:21 by rnugroho          #+#    #+#             */
/*   Updated: 2020/11/12 20:13:05 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void	vm_aff_print(t_process p)
{
	if (p.op.params[0].value < 1 || p.op.params[0].value > 16)
		return ;
	ft_printf("Aff: %c\n", p.reg[p.op.params[0].value]);
}
