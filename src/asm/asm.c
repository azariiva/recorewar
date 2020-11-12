/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:36:15 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/07 20:29:36 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <unistd.h>

static void		quedel(void *c, size_t cs)
{
	if (cs && c)
		ft_memdel(&c);
}

void			clear_parser(t_parse *parser)
{
	if (parser->lables)
		clear_label_htable(&(parser->lables));
	if (parser->op_htable)
		clear_op_htable(&(parser->op_htable));
	if (parser->tokens)
		ft_elistdel(&(parser->tokens));
}

static void		execute(char *file)
{
	t_parse	parser;

	ft_bzero(&parser, sizeof(t_parse));
	parser.tokens = ft_elistnew(sizeof(t_token), quedel);
	if ((parser.fdin = open(file, O_RDONLY)) < 0)
		error(ERR_OPEN_FILE, &parser);
	parse(&parser);
	get_op_htable(&parser);
	get_label_htable(&parser);
	collection(&parser);
	if ((parser.fdout = open(new_filename(file, ".cor"),
	O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
		error(ERR_CREATE_FILE, &parser);
	if (!parser.position)
		error(ERR_INVALID_CODE_SIZE, &parser);
	shaping(&parser);
	ft_printf("Writing output program to %s\n", new_filename(file, ".cor"));
	clear_parser(&parser);
	close(parser.fdin);
	close(parser.fdout);
}

int				main(int ac, char **av)
{
	if (ac == 2 && isrighttype(av[1]))
		execute(av[1]);
	else
		ft_printf_fd(STDERR_FILENO, "Wrong file type\n");
	return (0);
}
