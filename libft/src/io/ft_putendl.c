/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:43:50 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 19:55:46 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include <unistd.h>

int	ft_putendl(char const *s)
{
	return (ft_putendl_fd(s, STDOUT_FILENO));
}
