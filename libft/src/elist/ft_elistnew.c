/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elistnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:21:20 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/07 17:13:33 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_elist.h"
#include "libft_memory.h"

t_elist			*ft_elistnew(size_t content_size, void (*del)(void *, size_t))
{
	t_elist	*elist;

	if (!(del && content_size && (elist = ft_memalloc(sizeof(*elist)))))
		return (NULL);
	elist->content_size = content_size;
	elist->del = del;
	return (elist);
}
