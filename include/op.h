/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:34:20 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/08 15:42:34 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H

# define OP_H

# include <stdbool.h>

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define ALT_COMMENT_CHAR		';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_asop
{
	char		*name;
	u_int8_t	bytecode;
	int			arg_num;
	int			arg_types[3];
	bool		arg_types_code;
	int			t_dir_size;
}					t_asop;

static const t_asop	g_op_tab[16] =
{
	{
		.name = "live",
		.bytecode = 0x01,
		.arg_num = 1,
		.arg_types = {T_DIR, 0, 0},
		.arg_types_code = false,
		.t_dir_size = 4
	},
	{
		.name = "ld",
		.bytecode = 0x02,
		.arg_num = 2,
		.arg_types = {T_DIR | T_IND, T_REG, 0},
		.arg_types_code = true,
		.t_dir_size = 4
	},
	{
		.name = "st",
		.bytecode = 0x03,
		.arg_num = 2,
		.arg_types = {T_REG, T_IND | T_REG, 0},
		.arg_types_code = true,
		.t_dir_size = 4
	},
	{
		.name = "add",
		.bytecode = 0x04,
		.arg_num = 3,
		.arg_types = {T_REG, T_REG, T_REG},
		.arg_types_code = true,
		.t_dir_size = 4
	},
	{
		.name = "sub",
		.bytecode = 0x05,
		.arg_num = 3,
		.arg_types = {T_REG, T_REG, T_REG},
		.arg_types_code = true,
		.t_dir_size = 4
	},
	{
		.name = "and",
		.bytecode = 0x06,
		.arg_num = 3,
		.arg_types = {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		.arg_types_code = true,
		.t_dir_size = 4
	},
	{
		.name = "or",
		.bytecode = 0x07,
		.arg_num = 3,
		.arg_types = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.arg_types_code = true,
		.t_dir_size = 4
	},
	{
		.name = "xor",
		.bytecode = 0x08,
		.arg_num = 3,
		.arg_types = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.arg_types_code = true,
		.t_dir_size = 4
	},
	{
		.name = "zjmp",
		.bytecode = 0x09,
		.arg_num = 1,
		.arg_types = {T_DIR, 0, 0},
		.arg_types_code = false,
		.t_dir_size = 2
	},
	{
		.name = "ldi",
		.bytecode = 0x0a,
		.arg_num = 3,
		.arg_types = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.arg_types_code = true,
		.t_dir_size = 2
	},
	{
		.name = "sti",
		.bytecode = 0x0b,
		.arg_num = 3,
		.arg_types = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		.arg_types_code = true,
		.t_dir_size = 2
	},
	{
		.name = "fork",
		.bytecode = 0x0c,
		.arg_num = 1,
		.arg_types = {T_DIR, 0, 0},
		.arg_types_code = false,
		.t_dir_size = 2
	},
	{
		.name = "lld",
		.bytecode = 0x0d,
		.arg_num = 2,
		.arg_types = {T_DIR | T_IND, T_REG, 0},
		.arg_types_code = true,
		.t_dir_size = 4
	},
	{
		.name = "lldi",
		.bytecode = 0x0e,
		.arg_num = 3,
		.arg_types = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.arg_types_code = true,
		.t_dir_size = 2
	},
	{
		.name = "lfork",
		.bytecode = 0x0f,
		.arg_num = 1,
		.arg_types = {T_DIR, 0, 0},
		.arg_types_code = false,
		.t_dir_size = 2
	},
	{
		.name = "aff",
		.bytecode = 0x10,
		.arg_num = 1,
		.arg_types = {T_REG, 0, 0},
		.arg_types_code = true,
		.t_dir_size = 4
	}
};

#endif
