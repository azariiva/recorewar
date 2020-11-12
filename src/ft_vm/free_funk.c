/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:29:51 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/12 20:29:57 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		free_funk(t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->champ_size)
	{
		free(vm->champ[i].op);
		fta_clear(&(vm->processes));
		i++;
	}
}

int			free_err(t_vm *vm, int max, int errnum, char *file)
{
	int i;

	i = 0;
	while (i < max)
	{
		free(vm->champ[i].op);
		fta_clear(&(vm->processes));
		i++;
	}
	return (error(errnum, -1, (errnum == MALLOC) ? NULL : file));
}
