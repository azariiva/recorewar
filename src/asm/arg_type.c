/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:02:28 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/07 20:37:51 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_arg_type(t_token *token)
{
	if (token->type == INDIRECT || token->type == INDIRECT_LABLE)
		return (T_IND);
	else if (token->type == REGISTER)
		return (T_REG);
	else if (token->type == DIRECT_LABEL || token->type == DIRECT)
		return (T_DIR);
	return (0);
}
