/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:53:10 by fhilary           #+#    #+#             */
/*   Updated: 2020/08/03 15:22:53 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"
#include "libft_string.h"

int		ft_strccmp(const char *haystack, const char *needle, int c)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(haystack);
	len2 = ft_strlen(needle);
	return (ft_memccmp(haystack, needle, c, len2 > len1 ? len2 : len1));
}
