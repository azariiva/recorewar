/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:31:30 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/07 20:34:05 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			add_token(t_parse *parser, t_type type, char *line)
{
	t_token token;

	ft_bzero(&token, sizeof(token));
	token.type = type;
	token.row = parser->row;
	token.column = parser->column + 1;
	ft_elistpushbot(parser->tokens, &token);
	if (type == SEP)
		parser->column++;
	else if (type == COMMAND_NAME)
		parser->column += 5;
	else if (type == COMMAND_COMMENT)
		parser->column += 8;
	else if (type == STRING)
		string_parse(parser, line);
	else if (type == DIRECT_LABEL || type == INDIRECT_LABLE)
		lable_parse(parser, line);
	else if (type == DIRECT)
		number_parse(parser, line);
	else if (type == REGISTER)
		register_parse(parser, line);
	else if (type == INDIRECT)
		other_parse(parser, line);
}

void			pr_gettoken(t_parse *parser, char *line)
{
	if (line[parser->column] == '\n' &&
	!(parser->tokens && FT_QUETAIL(t_token, parser->tokens)->type == NEW_LINE))
		add_token(parser, NEW_LINE, line);
	else if (line[parser->column] == SEPARATOR_CHAR)
		add_token(parser, SEP, line);
	else if (ft_strnstr(line + parser->column, NAME_CMD_STRING, 5))
		add_token(parser, COMMAND_NAME, line);
	else if (ft_strnstr(line + parser->column, COMMENT_CMD_STRING, 8))
		add_token(parser, COMMAND_COMMENT, line);
	else if (line[parser->column] == '\"')
		add_token(parser, STRING, line);
	else if (line[parser->column] == DIRECT_CHAR)
	{
		if (line[parser->column + 1] == LABEL_CHAR)
			add_token(parser, DIRECT_LABEL, line);
		else
			add_token(parser, DIRECT, line);
	}
	else if (line[parser->column] == LABEL_CHAR)
		add_token(parser, INDIRECT_LABLE, line);
	else if (line[parser->column] == 'r' && register_len(parser, line))
		add_token(parser, REGISTER, line);
	else
		add_token(parser, INDIRECT, line);
}
