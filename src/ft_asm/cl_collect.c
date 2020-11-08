/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:45:46 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/07 20:54:17 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	info_collect_help(t_parse *parser, int name)
{
	t_token	*string;

	if (name)
	{
		if ((string = ((t_token *)ft_elistpoptop(parser->tokens)))->type
		!= STRING)
			error(ERR_NO_NAME_OR_COMMENT, parser);
		if (ft_strlen(string->content) > PROG_NAME_LENGTH)
			error(ERR_NAME_LEN, parser);
		ft_strcpy(parser->name, string->content);
	}
	else
	{
		if ((string = ((t_token *)ft_elistpoptop(parser->tokens)))->type
		!= STRING)
			error(ERR_NO_NAME_OR_COMMENT, parser);
		ft_strcpy(parser->comment, string->content);
	}
}

void		champ_info_collect(t_parse *parser)
{
	int		name;
	int		comment;
	t_token	*token;

	coll_skip_tokens(parser);
	name = 0;
	comment = 0;
	while (!name || !comment)
	{
		token = (t_token *)ft_elistpoptop(parser->tokens);
		if (token->type == COMMAND_NAME)
		{
			name = 1;
			info_collect_help(parser, 1);
		}
		else if (token->type == COMMAND_COMMENT)
		{
			comment = 1;
			info_collect_help(parser, 0);
		}
		else if (token->type != END_LINE && token->type != NEW_LINE)
			error(ERR_NO_NAME_OR_COMMENT, parser);
	}
}

void		mention_collect(t_parse *parser, t_token *token, int pos, int size)
{
	t_lable	*lable;
	t_lable	lable_name;

	parser->position += size;
	if (!(token->type == DIRECT_LABEL ||
	token->type == INDIRECT_LABLE))
		return ;
	ft_bzero(&lable_name, sizeof(t_lable));
	if (token->type == DIRECT_LABEL)
		ft_strcat(lable_name.name, token->content + 2);
	else
		ft_strcat(lable_name.name, token->content + 1);
	if (!(lable = ft_htget(parser->lables, &lable_name)))
		collect_error(ERR_INV_LABLE, token, parser);
	lable->mentions[lable->size++] = pos;
}

void		instruction_collect(t_parse *parser, t_dlist **tokens)
{
	t_asop	*asop;
	t_asop	op_name;
	int		arg_num;
	int		pos;

	ft_bzero(&op_name, sizeof(t_asop));
	op_name.name = FT_LSTCONT(t_token, *tokens)->content;
	if (!(asop = ft_htget(parser->op_htable, &op_name)))
		collect_error(ERR_INV_INST, FT_LSTCONT(t_token, *tokens), parser);
	pos = parser->position++;
	(arg_num = -1) && (parser->position += (asop->arg_types_code) ? 1 : 0);
	while (++arg_num < asop->arg_num && (*tokens = (*tokens)->next))
	{
		if (!(asop->arg_types[arg_num] & get_arg_type((*tokens)->content)))
			collect_error(ERR_INV_PRM, FT_LSTCONT(t_token, *tokens), parser);
		if (get_arg_type((*tokens)->content) & T_DIR)
			mention_collect(parser, (*tokens)->content, pos, asop->t_dir_size);
		else if (get_arg_type((*tokens)->content) & T_IND)
			mention_collect(parser, (*tokens)->content, pos, 2);
		parser->position += (get_arg_type((*tokens)->content) & T_REG ? 1 : 0);
		*tokens = (*tokens)->next;
		if (FT_LSTCONT(t_token, *tokens)->type != SEP &&
		FT_LSTCONT(t_token, *tokens)->type != END_LINE)
			collect_error(ERR_SYNTAX, FT_LSTCONT(t_token, *tokens), parser);
	}
}
