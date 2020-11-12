/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:17 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 19:34:53 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include <stddef.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		len;

	if (!(len = ft_strlen(needle)))
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_strnequ(needle, haystack, len))
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
