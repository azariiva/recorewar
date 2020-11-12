/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:58:49 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 15:23:43 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dlist.h"

static void	split(t_dlist *head, t_dlist **f, t_dlist **b)
{
	t_dlist	*ptr1;
	t_dlist	*ptr2;

	ptr2 = head;
	ptr1 = head->next;
	while (ptr1)
	{
		ptr1 = ptr1->next;
		if (ptr1)
		{
			ptr2 = ptr2->next;
			ptr1 = ptr1->next;
		}
	}
	*f = head;
	*b = ptr2->next;
	ptr2->next = NULL;
	(*b)->prev = NULL;
}

t_dlist		*merge(t_dlist *lst1, t_dlist *lst2,
int (*cmp)(t_dlist *, t_dlist *))
{
	t_dlist	*res;

	res = NULL;
	if (lst1 == NULL)
		return (lst2);
	if (lst2 == NULL)
		return (lst1);
	if (!cmp(lst1, lst2))
	{
		res = lst1;
		res->next = merge(lst1->next, lst2, cmp);
		res->next->prev = lst1;
	}
	else
	{
		res = lst2;
		res->next = merge(lst2->next, lst1, cmp);
		res->next->prev = lst2;
	}
	return (res);
}

void		ft_dlstsort(t_dlist **dlst, int (*cmp)(t_dlist *, t_dlist *))
{
	t_dlist	*head;
	t_dlist	*ptr1;
	t_dlist	*ptr2;

	if (!dlst || !*dlst || !(*dlst)->next)
		return ;
	head = *dlst;
	split(head, &ptr1, &ptr2);
	ft_dlstsort(&ptr1, cmp);
	ft_dlstsort(&ptr2, cmp);
	*dlst = merge(ptr1, ptr2, cmp);
}
