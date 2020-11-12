/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 02:14:07 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/07 17:01:36 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"
#include "libft_memory.h"
#include <stddef.h>

void	ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst || !del)
		return ;
	if ((*alst)->next)
		(*alst)->next->prev = (*alst)->prev;
	if ((*alst)->prev)
		(*alst)->prev->next = (*alst)->next;
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
