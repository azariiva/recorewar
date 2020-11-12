/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:49:13 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/07 20:53:59 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		collection(t_parse *parser)
{
	t_dlist		*tokens;
	t_lable		lable_name;

	champ_info_collect(parser);
	tokens = parser->tokens->head;
	while (tokens && FT_LSTCONT(t_token, tokens)->type != END_FILE)
	{
		if (FT_LSTCONT(t_token, tokens)->type == LABEL)
		{
			ft_bzero(&lable_name, sizeof(t_lable));
			ft_strncat(lable_name.name, FT_LSTCONT(t_token, tokens)->content,
			ft_strlen(FT_LSTCONT(t_token, tokens)->content) - 1);
			((t_lable *)ft_htget(parser->lables, &lable_name))->lab_pos =
			parser->position;
		}
		else if (FT_LSTCONT(t_token, tokens)->type == INSTRUCTION)
		{
			instruction_collect(parser, &tokens);
			if (FT_LSTCONT(t_token, tokens)->type != END_LINE)
				collect_error(ERR_SYNTAX, FT_LSTCONT(t_token, tokens), parser);
		}
		tokens = tokens->next;
	}
}
