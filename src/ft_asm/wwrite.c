/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wwrite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:05:05 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/07 18:15:06 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static short	*rev_2(short n)
{
	static short	out;

	out = (((n) >> 8) & 0x00FF) | (((n) << 8) & 0xFF00);
	return (&out);
}

static int		*rev_4(int n)
{
	static int		out;

	out = (((n) >> 24) & 0x000000FF) | (((n) >> 8) & 0x0000FF00) |
	(((n) << 8) & 0x00FF0000) | (((n) << 24) & 0xFF000000);
	return (&out);
}

void			wwrite(t_parse *parser, int n, int size)
{
	if (size == 4)
		write(parser->fdout, rev_4(n), size);
	else if (size == 2)
		write(parser->fdout, rev_2((short)n), size);
	else
		write(parser->fdout, &n, size);
}
