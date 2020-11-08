/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:18:56 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/07 18:30:35 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		string_parse(t_parse *parser, char *line)
{
	char	*newline;

	line += parser->column + 1;
	while (!ft_strchr(line, '\"') &&
	get_next_line(parser->fdin, &newline) == OK && ++parser->row)
	{
		line = ft_strjoin(line, "\n");
		line = ft_strjoin(line, newline);
		ft_strdel(&newline);
	}
	if (line[ft_strlen(line) - 1] != '\"')
		error(ERR_STRING, parser);
	if (ft_strlen(line) - 1 > COMMENT_LENGTH)
		error(ERR_LEN_STRING, parser);
	parser->column += ft_strlen(line) + 1;
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL), line,
	ft_strlen(line) - 1);
}

void		number_parse(t_parse *parser, char *line)
{
	int		len;

	len = parser->column + 1;
	if (line[len] == '-')
		len++;
	while (line[len] && ft_isdigit(line[len]))
		len++;
	if (!(len - parser->column - 1) || const_check(line[len]))
		lex_error(parser, parser->column + len);
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
	line + parser->column, len - parser->column);
	parser->column = len;
}

void		lable_parse(t_parse *parser, char *line)
{
	int		len;

	len = parser->column + 2;
	while (line[len] && is_symbol(line[len]))
		len++;
	if (const_check(line[len]))
		lex_error(parser, parser->column + len);
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
	line + parser->column, len - parser->column);
	parser->column = len;
}

void		register_parse(t_parse *parser, char *line)
{
	int		len;

	len = register_len(parser, line) + 1;
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
	line + parser->column, len);
	parser->column += len;
}

void		other_parse(t_parse *parser, char *line)
{
	int		len;
	int		flag;

	flag = 0;
	len = line[parser->column] == '-' ? parser->column + 1 : parser->column;
	while (line[len] && is_symbol(line[len]))
		flag += ft_isalpha(line[len++]) ? 1 : 0;
	if (line[len] == ':' && len > parser->column)
	{
		GET_PTOKENS(parser, type, FT_QUETAIL) = LABEL;
		parser->label_count++;
		ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
		line + parser->column, len + 1 - parser->column);
		parser->column += len + 1;
		return ;
	}
	if (const_check(line[len]) && line[len] != DIRECT_CHAR && line[len] != '-')
		lex_error(parser, parser->column + len);
	if (flag)
		GET_PTOKENS(parser, type, FT_QUETAIL) = INSTRUCTION;
	ft_strncpy(GET_PTOKENS(parser, content, FT_QUETAIL),
	line + parser->column, len - parser->column);
	parser->column = len;
}
