/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ctype.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:54:17 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/16 15:01:50 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CTYPE_H

# define LIBFT_CTYPE_H

/*
** TODO: Write descriptions
*/
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isblank(int c);
int	ft_iscntrl(int c);
int	ft_isdigit(int c);
int	ft_isgraph(int c);
int	ft_islower(int c);
int	ft_isprint(int c);
int	ft_ispunct(int c);
int	ft_isspace(int c);
int	ft_isupper(int c);
int	ft_isxdigit(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);

int	ft_strisnum(char *str);

#endif
