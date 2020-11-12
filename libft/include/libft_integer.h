/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_integer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:30:35 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/23 15:15:23 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INTEGER_H

# define LIBFT_INTEGER_H

/*
** The ft_abs() function computes the absolute value of the integer i.
*/
int				ft_abs(int i);
/*
** The ft_labs() function returns the absolute value of the long integer i.
*/
long			ft_labs(long i);
/*
** The ft_llabs() function returns the absolute value of i.
*/
long long		ft_llabs(long long i);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
char			*ft_lltoa(long long n);
char			*ft_ulltoa_base(unsigned long long num, int base);
int				ft_atou(char const *str);
long long		ft_atoll(char const *str);

#endif
