/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:53:09 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/12 20:27:47 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "libft_printf.h"
# include "libft_get_next_line.h"
# include "op.h"

# define ERR_PARSER_INIT		"ERROR: Can\'t initialize parser"
# define ERR_TOKEN_INIT			"ERROR: Can\'t initialize token"
# define ERR_STATEMENT_INIT		"ERROR: Can\'t initialize statement"
# define ERR_OPEN_FILE			"ERROR: Can\'t open file with champion"
# define ERR_READ_FILE			"ERROR: Can\'t read file with champion"
# define ERR_CREATE_FILE		"ERROR: Can\'t create file"
# define ERR_INVALID_FILE		"ERROR: Invalid file with champion"
# define ERR_INVALID_MAGIC		"ERROR: Invalid magic header"
# define ERR_NO_NULL			"ERROR: No null control bytes"
# define ERR_CODE_INIT			"ERROR: Can\'t initialize string of code"
# define ERR_INVALID_CODE_SIZE	"ERROR: Invalid code size"

# define LEXICAL_ERROR			"Lexical error at"
# define ERR_STRING				"Error in name or comment string"
# define ERR_LEN_STRING			"String too long (Max length 2048)"
# define ERR_NAME_LEN			"Champion name too long (Max length 128)"
# define ERR_COMMENT_LEN		"Champion comment too long (Max length 2048)"
# define ERR_NO_NAME_OR_COMMENT	"Champion has no name or comment"
# define ERR_INV_INST			"Invalid instruction"
# define ERR_INV_PRM			"Invalid parameter"
# define ERR_SYNTAX				"Syntax error"
# define ERR_INV_LABLE			"Invalid lable"

typedef enum	e_type
{
	LABEL,
	INSTRUCTION,
	COMMAND_NAME,
	COMMAND_COMMENT,
	INDIRECT,
	INDIRECT_LABLE,
	REGISTER,
	SEP,
	DIRECT_LABEL,
	DIRECT,
	STRING,
	COMMAND,
	NEW_LINE,
	END_LINE,
	END_FILE
}				t_type;

# define TSTR(T) (g_typearr[T])

typedef struct	s_token
{
	char	content[COMMENT_LENGTH];
	t_type	type;
	int		row;
	int		column;
	int		position;
}				t_token;

typedef struct	s_lable
{
	char	name[CHAMP_MAX_SIZE];
	int32_t	lab_pos;
	int		mentions[CHAMP_MAX_SIZE];
	int		size;
	int		m_position;
}				t_lable;

typedef struct	s_parse
{
	char		name[PROG_NAME_LENGTH];
	char		comment[COMMENT_LENGTH];
	int			fdin;
	int			fdout;
	int			row;
	int			column;
	t_elist		*tokens;
	int32_t		position;
	int			label_count;
	t_htable	*op_htable;
	t_htable	*lables;
}				t_parse;

# define GET_TF(ts, f, HT) (HT(t_token, ts)->f)
# define GET_PTOKENS(p, f, HT) (GET_TF(p->tokens, f, HT))

int				isrighttype(char *name);
char			*new_filename(char *file, char *type);

void			add_token(t_parse *parser, t_type type, char *line);

void			parse(t_parse *parser);
int				pr_skip_space(t_parse *parser, char *line);
void			pr_gettoken(t_parse *parser, char *line);
void			string_parse(t_parse *parser, char *line);
void			lable_parse(t_parse *parser, char *line);
void			number_parse(t_parse *parser, char *line);
void			register_parse(t_parse *parser, char *line);
int				register_len(t_parse *parser, char *line);
void			other_parse(t_parse *parser, char *line);
int				const_check(char c);
int				is_symbol(char c);

void			collection(t_parse *parser);
void			coll_skip_tokens(t_parse *parser);
void			champ_info_collect(t_parse *parser);
void			mention_collect(t_parse *parser, t_token *token,
int pos, int size);
void			champ_info_collect(t_parse *parser);
void			instruction_collect(t_parse *parser, t_dlist **tokens);

void			collect_error(char *type, t_token *token, t_parse *parser);
void			lex_error(t_parse *parser, int column);
void			error(char *err, t_parse *parser);

void			shaping(t_parse *parser);

void			show_tokens(t_parse *parser);

int				get_arg_type(t_token *token);
void			get_label_htable(t_parse *parser);
void			get_op_htable(t_parse *parser);

void			clear_label_htable(t_htable **lht);
void			clear_op_htable(t_htable **oht);
void			clear_parser(t_parse *parse);

void			wwrite(t_parse *parser, int n, int size);

#endif
