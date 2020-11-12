/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_float.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 01:05:58 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/09 15:07:15 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FLOAT_H
# define LIBFT_FLOAT_H

int		ft_lftoa_rounding(long double f_part_c, int precision,
				long double *f_part, long long *i_part);
void	ft_lftoa_set_other_nums(int i, char **result);
void	ft_lftoa_add_number(int *i, char **result, long double *f_part);
char	*ft_lftoa(long double n, int precision);

#endif
