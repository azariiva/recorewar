/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_compiler_header.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:08:15 by rnugroho          #+#    #+#             */
/*   Updated: 2018/04/18 15:21:21 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

void
	asm_append_nullbyte(t_array *binary)
{
	fta_append_free(binary, asm_to_big_endian(0x0, 4), 4);
}

void
	asm_append_name(t_array *binary, char *str)
{
	int		i;
	char	*temp;

	temp = ft_re_capture("[^\"]+", str);
	fta_append(binary, temp, ft_strlen(temp));
	i = ft_strlen(temp);
	while (i < PROG_NAME_LENGTH)
	{
		fta_append_char(binary, 0x00);
		i++;
	}
	asm_append_nullbyte(binary);
	free(temp);
}

void
	asm_append_comment(t_array *binary, char *str)
{
	int		i;
	char	*temp;

	temp = ft_re_capture("[^\"]+", str);
	fta_append(binary, temp, ft_strlen(temp));
	i = ft_strlen(temp);
	while (i < COMMENT_LENGTH)
	{
		fta_append_char(binary, 0x00);
		i++;
	}
	asm_append_nullbyte(binary);
	free(temp);
}

void
	asm_append_size(t_array *binary, int size)
{
	fta_append_free(binary, asm_to_big_endian(size, 4), 4);
}
