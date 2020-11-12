/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 02:26:45 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 13:45:49 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"
#include <stddef.h>

static t_dlist	*ft_dlstmap2(t_dlist *lst, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist		*next;
	t_dlist		*head;
	t_dlist		*ptr;

	next = lst->next;
	if (!(head = f(lst)))
		return (NULL);
	lst = next;
	ptr = head;
	while (lst && ptr)
	{
		next = lst->next;
		ptr->next = f(lst);
		ptr->next->prev = ptr;
		ptr = ptr->next;
		lst = next;
	}
	return (head);
}

t_dlist			*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist	*prev;
	t_dlist	*head;
	t_dlist	*ptr;

	if (!lst)
		return (NULL);
	prev = lst->prev;
	if (!(head = ft_dlstmap2(lst, f)))
		return (NULL);
	lst = prev;
	ptr = head->prev;
	while (lst && ptr)
	{
		prev = lst->prev;
		ptr->prev = f(lst);
		ptr->prev->next = ptr;
		ptr = ptr->prev;
		lst = prev;
	}
	return (head);
}
