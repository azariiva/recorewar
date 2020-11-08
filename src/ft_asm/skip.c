/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:31:52 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/07 20:46:57 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		pr_skip_space(t_parse *parser, char *line)
{
	while (ft_isspace(line[parser->column]))
		parser->column++;
	if (line[parser->column] == COMMENT_CHAR ||
	line[parser->column] == ALT_COMMENT_CHAR)
	{
		while (line[parser->column])
			parser->column++;
	}
	return (OK);
}

void	coll_skip_tokens(t_parse *parser)
{
	while (GET_PTOKENS(parser, type, FT_QUEHEAD) == NEW_LINE ||
	GET_PTOKENS(parser, type, FT_QUEHEAD) == END_LINE)
		ft_elistpoptop(parser->tokens);
}
