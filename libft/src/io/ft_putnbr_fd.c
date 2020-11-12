/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:17 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 19:57:35 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "libft_integer.h"
#include <unistd.h>

int		ft_putnbr_fd(int n, int fd)
{
	char	buf[21];
	char	*ptr;
	int		negative;
	ssize_t	written;

	ptr = buf + 20;
	negative = (n < 0 ? 1 : 0);
	*ptr-- = ft_abs(n % 10) + '0';
	n = ft_abs(n / 10);
	while (n)
	{
		*ptr-- = n % 10 + '0';
		n /= 10;
	}
	if (negative)
		*ptr-- = '-';
	if ((written = write(fd, ptr + 1, 20 - (ptr - buf))) == -1)
		return (EOF);
	else
		return (written);
}
