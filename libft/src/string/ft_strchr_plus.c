/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 21:04:47 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 19:41:32 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char		*ft_strchr_plus(const char *s, int (*cmp)(int))
{
	while (*s)
	{
		if (cmp(*s))
			return ((char *)s);
		++s;
	}
	if (cmp(*s))
		return ((char *)s);
	return (NULL);
}
