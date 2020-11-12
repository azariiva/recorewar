/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:17 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 20:20:48 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"

int	ft_putendl_fd(char const *s, int fd)
{
	int	written;

	if ((written = ft_putstr_fd(s, fd)) == EOF)
		return (EOF);
	else if (ft_putchar_fd('\n', fd) < 0)
		return (written);
	else
		return (written + 1);
}
