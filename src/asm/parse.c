/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:32:10 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/12 20:30:21 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		parse(t_parse *parser)
{
	char	*line;
	int		row;
	size_t	size;

	while (++parser->row
	&& (size = get_next_line(parser->fdin, &line)) == FT_OK)
	{
		row = parser->row;
		!(parser->column = 0) ? pr_skip_space(parser, line) : 0;
		if (!line[parser->column] && !(parser->tokens->tail &&
		FT_QUETAIL(t_token, parser->tokens)->type == NEW_LINE))
			add_token(parser, NEW_LINE, line);
		while (row == parser->row && line[parser->column])
		{
			if (pr_skip_space(parser, line) && line[parser->column])
				pr_gettoken(parser, line);
		}
		if (GET_PTOKENS(parser, type, FT_QUETAIL) != NEW_LINE)
			add_token(parser, END_LINE, line);
		ft_strdel(&line);
	}
	if ((int)size == FT_ERR)
		error(ERR_READ_FILE, parser);
	if (size == FT_END)
		add_token(parser, END_FILE, line);
}
