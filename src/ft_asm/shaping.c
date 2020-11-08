/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:17:55 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/07 20:55:18 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_arg_type_code(t_parse *parser)
{
	t_dlist		*tokens;
	int			x;
	int			i;

	x = 0;
	tokens = parser->tokens->head;
	i = 3;
	while (FT_LSTCONT(t_token, tokens)->type != END_LINE)
	{
		if (get_arg_type(tokens->content) & T_DIR)
			x |= (1 << (i-- * 2 + 1));
		else if (get_arg_type(tokens->content) & T_REG)
			x |= (1 << (i-- * 2));
		else if (get_arg_type(tokens->content) & T_IND)
		{
			x |= (1 << (i * 2));
			x |= (1 << (i-- * 2 + 1));
		}
		tokens = tokens->next;
	}
	return (x);
}

void	dir_shape(t_parse *parser, t_token *token, t_asop *asop)
{
	t_lable	*lable;
	t_lable	lable_name;

	if (token->type == DIRECT_LABEL)
	{
		ft_bzero(&lable_name, sizeof(t_lable));
		ft_strcat(lable_name.name, token->content + 2);
		lable = ft_htget(parser->lables, &lable_name);
		wwrite(parser, lable->lab_pos - lable->mentions[lable->m_position++],
		asop->t_dir_size);
	}
	else
		wwrite(parser, ft_atoi(&token->content[1]), asop->t_dir_size);
}

void	ind_shape(t_parse *parser, t_token *token)
{
	t_lable	*lable;
	t_lable	lable_name;

	if (token->type == INDIRECT_LABLE)
	{
		ft_bzero(&lable_name, sizeof(t_lable));
		ft_strcat(lable_name.name, token->content + 1);
		lable = ft_htget(parser->lables, &lable_name);
		wwrite(parser, lable->lab_pos - lable->mentions[lable->m_position++],
		2);
	}
	else
		wwrite(parser, ft_atoi(token->content), 2);
}

void	instruct_shape(t_parse *parser, t_token *token)
{
	t_asop	*asop;
	t_asop	op_name;

	ft_bzero(&op_name, sizeof(t_asop));
	op_name.name = token->content;
	asop = ft_htget(parser->op_htable, &op_name);
	wwrite(parser, asop->bytecode, 1);
	if (asop->arg_types_code)
		wwrite(parser, get_arg_type_code(parser), 1);
	while ((token = (t_token *)ft_elistpoptop(parser->tokens))->type !=
	END_LINE)
	{
		if (get_arg_type(token) & T_REG)
			wwrite(parser, ft_atoi(&FT_LSTCONT(t_token, token)->content[1]), 1);
		else if (get_arg_type(token) & T_DIR)
			dir_shape(parser, FT_LSTCONT(t_token, token), asop);
		else if (get_arg_type(token) & T_IND)
			ind_shape(parser, FT_LSTCONT(t_token, token));
	}
}

void	shaping(t_parse *parser)
{
	t_token	*token;

	wwrite(parser, COREWAR_EXEC_MAGIC, 4);
	write(parser->fdout, parser->name, sizeof(parser->name));
	wwrite(parser, 0, 4);
	wwrite(parser, parser->position, 4);
	write(parser->fdout, parser->comment, sizeof(parser->comment));
	wwrite(parser, 0, 4);
	while ((token = (t_token *)ft_elistpoptop(parser->tokens))->type !=
	END_FILE)
	{
		if (token->type == INSTRUCTION)
			instruct_shape(parser, token);
	}
}
