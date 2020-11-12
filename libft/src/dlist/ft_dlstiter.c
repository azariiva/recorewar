/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 02:20:55 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 02:26:26 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"

void	ft_dlstiter_b(t_dlist *lst, void (*f)(t_dlist *elem))
{
	t_dlist	*prev;

	while (lst)
	{
		prev = lst->prev;
		f(lst);
		lst = prev;
	}
}

void	ft_dlstiter_f(t_dlist *lst, void (*f)(t_dlist *elem))
{
	t_dlist	*next;

	while (lst)
	{
		next = lst->next;
		f(lst);
		lst = next;
	}
}
