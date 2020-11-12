/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:35:34 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 19:13:14 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_ctype.h"
#include <stddef.h>

char	*ft_strtrim(char const *s)
{
	char const	*start;
	char		*end;
	size_t		len;

	if (!s)
		return (NULL);
	start = s;
	while (*start && ft_isspace(*start))
		++start;
	if (!*start)
		len = 0;
	else
	{
		end = (char *)s + ft_strlen(s) - 1;
		while (ft_isspace(*end))
			--end;
		len = end - start + 1;
	}
	return (ft_strsub(s, start - s, len));
}
