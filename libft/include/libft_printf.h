/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 02:23:03 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/12 14:58:51 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include "libft_pfbuffer.h"
# include <stdarg.h>

typedef enum	e_typemod
{
	L_MOD = 1 << 0,
	LL_MOD = 1 << 1,
	H_MOD = 1 << 2,
	HH_MOD = 1 << 3,
	CAP_L_MOD = 1 << 4,
	J_MOD = 1 << 5,
	Z_MOD = 1 << 6
}				t_typemod;

typedef enum	e_typefg
{
	MIN_FLAG = 1 << 0,
	PLUS_FLAG = 1 << 1,
	SPACE_FLAG = 1 << 2,
	ZERO_FLAG = 1 << 3,
	HASH_FLAG = 1 << 4
}				t_typefg;

typedef struct	s_pf
{
	t_typefg	flag;
	int			width;
	int			prec;
	int			fd;
	t_typemod	mod;
	char		data_type;
	int			len;
	t_buf		buf;
}				t_pf;

# define ANSI_RED "\e[0;31m"
# define ANSI_BOLD_RED "\e[1;31m"
# define ANSI_GREEN "\e[0;32m"
# define ANSI_BOLD_GREEN "\e[1;32m"
# define ANSI_YELLOW "\e[0;33m"
# define ANSI_BOLD_YELLOW "\e[1;33m"
# define ANSI_BLUE "\e[0;34m"
# define ANSI_BOLD_BLUE "\e[1;34m"
# define ANSI_MAGENTA "\e[0;35m"
# define ANSI_BOLD_MAGENTA "\e[1;35m"
# define ANSI_CYAN "\e[0;36m"
# define ANSI_BOLD_CYAN "\e[1;36m"
# define ANSI_EOC "\e[0m"

int				ft_printf(const char *format, ...);
int				ft_printf_fd(int fd, const char *format, ...);
void			parse_placeholder(t_pf *pf, const char *fmt, va_list va, \
									int *i);
int				is_flag(char c);
int				is_modifier(char c);
int				is_data_type(char c);
void			validate_flags(t_pf *pf);
void			if_nothing(t_pf *pf, const char *fmt, int *i);
void			print_zero_flag_num(t_pf *pf, int diff, char *tmp);
void			print_no_zero_flag_num(t_pf *pf, int diff, char *tmp);
void			print_precision(t_pf *pf, char *num);
void			print_placeholder(t_pf *pf, va_list va);
int				print_num_d(t_pf *pf, long long num);
int				print_float(t_pf *pf, long double num);
void			print_txt(t_pf *pf, va_list va);
void			print_base(t_pf *pf, va_list va);
void			print_txt_c(t_pf *pf, char c);
void			print_txt_s(t_pf *pf, char *str);
int				print_b(t_pf *pf, unsigned long long num, int base);
int				calc_diff(t_pf *pf, char *num);
void			print_plus_space_flag(t_pf *pf, char *num);
void			print_color(t_pf *pf, const char *fmt, int *i);

#endif
