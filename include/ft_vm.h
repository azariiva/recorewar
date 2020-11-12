/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:39:11 by rnugroho          #+#    #+#             */
/*   Updated: 2020/11/12 20:12:57 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VM_H
# define FT_VM_H

# include "libft.h"
# include "op.h"

# define EOC 0
# define RED 1
# define GREEN 2

# define MALLOC			1
# define CHAMP_MIN		2
# define CHAMP_MAX		3
# define INVALID_FILE	4
# define INVALID_HEADER	5
# define INVALID_MAGIC	6
# define INVALID_INSTR	7
# define NO_CODE		8
# define CODE_MAX		9

# define VISU			0

# define V_LVL_2		0
# define V_LVL_4		1
# define V_LVL_8		2
# define V_LVL_16		3

typedef struct	s_param
{
	int			type;
	int			size;
	int			value;
}				t_param;

typedef struct	s_op
{
	int			opcode;
	int			oc;
	int			size;
	t_param		params[3];
	int			param_c;
}				t_op;

typedef struct	s_process
{
	int			offset;
	int			cycles;
	int			pc;
	int			pc_next;
	int			live_nbr;
	int			live_cycle;
	int			champ;
	int			carry;
	int			reg[REG_NUMBER + 1];
	t_op		op;
	int			index;
}				t_process;

typedef struct	s_champ
{
	t_header	header;
	char		*op;
	int			live_nbr;
	char		*path;
}				t_champ;

typedef struct	s_vm
{
	int			dump;
	int			cycles;
	int			option_v[4];
	int			opt_num;
	int			check_nbr;
	char		*players[MAX_PLAYERS + 1];
	t_champ		champ[4];
	t_array		processes;
	int			process_index;
	int			champ_size;
	int			last_dead_champ;
	int			winner;
}				t_vm;

unsigned char	g_memory[MEM_SIZE];
unsigned char	g_memory_mark[MEM_SIZE];
int				g_cycles;
int				g_cycles_to;
int				g_cycles_to_die;
int				g_max_check;
int				g_live_nbr;

int				options(char **av, t_vm *vm);
int				print_usage(char **av, int status);
void			init_globals(void);

int				error(int errnum, int status, char *name);

void			free_funk(t_vm *vm);
int				free_err(t_vm *vm, int max, int errnum, char *file);

int				read_binaries(char **paths, t_vm *vm);
void			st_mem(int index, char *value, int champ, int size);
int				ldd_memory(int index, int size);
int				ld_funk(int index, int size, char *op);

void			decomp_param(t_process *p, t_op *op);
int				decomp_op(t_vm *vm, t_process *p);

int				checker(t_vm *vm);

void			exec(t_vm *vm);

char			*big_end_convert(int value, int size);
void			op_include(t_vm *vm, t_process *p);

int				param_check(t_op op);
void			live_op(t_vm *vm, t_process *p);
void			ld_op(t_vm *vm, t_process *p);
void			st_op(t_vm *vm, t_process *p);
void			add_op(t_vm *vm, t_process *p);
void			sub_op(t_vm *vm, t_process *p);
void			and_op(t_vm *vm, t_process *p);
void			or_op(t_vm *vm, t_process *p);
void			xor_op(t_vm *vm, t_process *p);
void			zjmp_op(t_vm *vm, t_process *p);
void			ldi_op(t_vm *vm, t_process *p);
void			sti_op(t_vm *vm, t_process *p);
void			fork_op(t_vm *vm, t_process *p);
void			lld_op(t_vm *vm, t_process *p);
void			lldi_op(t_vm *vm, t_process *p);
void			lfork_op(t_vm *vm, t_process *p);
void			vm_op_print(t_process p);
void			vm_live_print(t_process p);
void			vm_ld_print(t_process p);
void			vm_st_print(t_process p);
void			vm_add_print(t_process p);
void			vm_sub_print(t_process p);
void			vm_and_print(t_process p);
void			vm_or_print(t_process p);
void			vm_xor_print(t_process p);
void			vm_zjmp_print(t_process p);
void			vm_ldi_print(t_process p);
void			vm_sti_print(t_process p);
void			vm_fork_print(t_process p);
void			vm_lld_print(t_process p);
void			vm_lldi_print(t_process p);
void			vm_lfork_print(t_process p);
void			vm_aff_print(t_process p);

int				init_p(t_process *p, int i);
int				cursor_(t_process *p, int param1, int param2, int i);

int				check_valid_arg(char *arg, t_vm *vm);
int				check_val_verb(int v);
void			set_v(int v, t_vm *vm);
int				isnumber(char *str);
int				ft_abs(int i);

typedef struct	s_op_dict
{
	char		*name;
	int			opcode;
	int			d_size;
	int			param_c;
	int			is_oc;
	int			p_type[3];
	void		*opfunc;
	void		*opprint;
	int			is_car;
	int			cycles;
}				t_op_dict;

static	t_op_dict g_op_dict[17] = {
	{ .name = "\0", .opcode = 0x00, .d_size = 0, .param_c = 0, .is_oc = 0,
		{0, 0, 0}, &op_include, &vm_op_print, .is_car = 0, .cycles = 0},
	{ .name = "live", .opcode = 0x01, .d_size = 4, .param_c = 1, .is_oc = 0,
		{T_DIR, 0, 0}, &live_op, &vm_live_print, .is_car = 0, .cycles = 10},
	{ .name = "ld", .opcode = 0x02, .d_size = 4, .param_c = 2, .is_oc = 1,
		{T_DIR | T_IND, T_REG, 0},
		&ld_op, &vm_ld_print, .is_car = 1, .cycles = 5},
	{ .name = "st", .opcode = 0x03, .d_size = 4, .param_c = 2, .is_oc = 1,
		{T_REG, T_REG | T_IND, 0},
		&st_op, &vm_st_print, .is_car = 0, .cycles = 5},
	{ .name = "add", .opcode = 0x04, .d_size = 4, .param_c = 3, .is_oc = 1,
		{T_REG, T_REG, T_REG},
		&add_op, &vm_add_print, .is_car = 1, .cycles = 10},
	{ .name = "sub", .opcode = 0x05, .d_size = 4, .param_c = 3, .is_oc = 1,
		{T_REG, T_REG, T_REG},
		&sub_op, &vm_sub_print, .is_car = 1, .cycles = 10},
	{ .name = "and", .opcode = 0x06, .d_size = 4, .param_c = 3, .is_oc = 1,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		&and_op, &vm_and_print, .is_car = 1, .cycles = 6},
	{ .name = "or", .opcode = 0x07, .d_size = 4, .param_c = 3, .is_oc = 1,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		&or_op, &vm_or_print, .is_car = 1, .cycles = 6},
	{ .name = "xor", .opcode = 0x08, .d_size = 4, .param_c = 3, .is_oc = 1,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		&xor_op, &vm_xor_print, .is_car = 1, .cycles = 6},
	{ .name = "zjmp", .opcode = 0x09, .d_size = 2, .param_c = 1, .is_oc = 0,
		{T_DIR, 0, 0},
		&zjmp_op, &vm_zjmp_print, .is_car = 0, .cycles = 20},
	{ .name = "ldi", .opcode = 0x0a, .d_size = 2, .param_c = 3, .is_oc = 1,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		&ldi_op, &vm_ldi_print, .is_car = 0, .cycles = 25},
	{ .name = "sti", .opcode = 0x0b, .d_size = 2, .param_c = 3, .is_oc = 1,
		{T_REG, T_REG | T_IND | T_DIR, T_DIR | T_REG},
		&sti_op, &vm_sti_print, .is_car = 0, .cycles = 25},
	{ .name = "fork", .opcode = 0x0c, .d_size = 2, .param_c = 1, .is_oc = 0,
		{T_DIR, 0, 0}, &fork_op, &vm_fork_print, .is_car = 0, .cycles = 800},
	{ .name = "lld", .opcode = 0x0d, .d_size = 4, .param_c = 2, .is_oc = 1,
		{T_IND | T_DIR, T_REG, 0},
		&lld_op, &vm_lld_print, .is_car = 1, .cycles = 10},
	{ .name = "lldi", .opcode = 0x0e, .d_size = 2, .param_c = 3, .is_oc = 1,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		&lldi_op, &vm_lldi_print, .is_car = 0, .cycles = 50},
	{ .name = "lfork", .opcode = 0x0f, .d_size = 2, .param_c = 1, .is_oc = 0,
		{T_DIR, 0, 0},
		lfork_op, &vm_lfork_print, .is_car = 0, .cycles = 1000},
	{ .name = "aff", .opcode = 0x10, .d_size = 4, .param_c = 1, .is_oc = 1,
		{T_REG, 0, 0}, &op_include, &vm_aff_print, .is_car = 0, .cycles = 2}
};

#endif
