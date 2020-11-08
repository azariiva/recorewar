/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:48:12 by fpetras           #+#    #+#             */
/*   Updated: 2020/11/08 14:00:48 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

static void	ft_error_2(int errnum)
{
	if (errnum == OP_EMPTY)
		ft_printf_fd(2, "Error - No operation found\n");
	else if (errnum == OP_PARAM)
		ft_printf_fd(2, "Error - Parameter is invalid\n");
	else if (errnum == OP_PARAM_TYPE)
		ft_printf_fd(2, "Error - Parameter type is invalid\n");
	else if (errnum == LABEL_MISSING)
		ft_printf_fd(2, "Error - Label is undefined\n");
	else if (errnum == LABEL_INVALID)
		ft_printf_fd(2, "Error - Label is invalid\n");
}

int			ft_error(int errnum, int status, char *line)
{
	if (line)
		ft_printf_fd(2, "%*w%s%w\n", RED, line);
	if (errnum == NEWLINE)
	{
		ft_printf_fd(2, "Error - unexpected end of input\n");
		ft_printf_fd(2, "(Perhaps you forgot to end with a newline ?)\n");
	}
	if (errnum == EMPTY)
		ft_printf_fd(2, "Error - File is empty\n");
	if (errnum == MALLOC)
		ft_printf_fd(2, "Error - Malloc 💥\n");
	if (errnum == HEADER)
		ft_printf_fd(2, "Error - Header\n");
	else if (errnum == NAME_LEN)
		ft_printf_fd(2, "Error - Maximum name length exceeded\n");
	else if (errnum == COMMENT_LEN)
		ft_printf_fd(2, "Error - Maximum comment length exceeded\n");
	else if (errnum == OP)
		ft_printf_fd(2, "Error - Operation is invalid\n");
	else if (errnum == OP_NAME)
		ft_printf_fd(2, "Error - Operation does not exist\n");
	else
		ft_error_2(errnum);
	return (status);
}
