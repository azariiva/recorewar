/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_htable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:36:37 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/07 18:14:55 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int				cmp(const void *a, const void *b)
{
	t_asop	*ta;
	t_asop	*tb;

	ta = (t_asop *)a;
	tb = (t_asop *)b;
	return (ft_strcmp(ta->name, tb->name));
}

static unsigned long	hash(const void *tab, const size_t modulo)
{
	t_asop	*t;

	t = (t_asop *)tab;
	return (ft_strhash(t->name, modulo));
}

static void				del(void *c, size_t cs)
{
	if (c && cs)
		ft_memdel(&c);
}

void					clear_op_htable(t_htable **oht)
{
	ft_htdel(oht, del);
}

void					get_op_htable(t_parse *parser)
{
	size_t		i;

	parser->op_htable = ft_htnew((sizeof(g_op_tab) / sizeof(*g_op_tab)),
	cmp, hash);
	i = -1;
	while (++i < (sizeof(g_op_tab) / sizeof(*g_op_tab)))
		ft_htadd(parser->op_htable, g_op_tab + i, sizeof(*g_op_tab));
}
