/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:17 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 19:56:47 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "libft_string.h"
#include <unistd.h>

int	ft_putstr_fd(char const *str, int fd)
{
	ssize_t	len;
	ssize_t	written;

	len = ft_strlen(str);
	if ((written = write(fd, str, len * sizeof(*str))) == -1)
		return (EOF);
	else
		return (written);
}
