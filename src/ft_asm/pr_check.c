/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:32:08 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/07 18:42:29 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			const_check(char c)
{
	return (c && !ft_isspace(c) && c != '-' &&
	c != SEPARATOR_CHAR && c != COMMENT_CHAR && c != ALT_COMMENT_CHAR);
}

int			is_symbol(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_'));
}

int			register_len(t_parse *parser, char *line)
{
	int		len;
	int		curlen;

	curlen = 0;
	len = parser->column + 1;
	while (line[len] && ft_isdigit(line[len++]))
		curlen++;
	return ((curlen > 0 && curlen < 3) ? curlen : 0);
}
