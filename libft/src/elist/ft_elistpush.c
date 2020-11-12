/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elistpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:30:11 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/07 18:10:36 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_elist.h"

int	ft_elistpushtop(t_elist *elist, void *content)
{
	t_dlist	*new;

	if (!(elist && content && (new = ft_dlstnew(content, elist->content_size))))
		return (FT_ERR);
	if (elist->head)
	{
		new->next = elist->head;
		elist->head->prev = new;
		elist->head = new;
	}
	else
	{
		elist->head = new;
		elist->tail = new;
	}
	if (!elist->tail)
		elist->tail = elist->head;
	return (FT_OK);
}

int	ft_elistpushbot(t_elist *elist, void *content)
{
	t_dlist	*new;

	if (!(elist && content && (new = ft_dlstnew(content, elist->content_size))))
		return (FT_ERR);
	if (elist->tail)
	{
		elist->tail->next = new;
		new->prev = elist->tail;
		elist->tail = new;
	}
	else
	{
		elist->tail = new;
		elist->head = elist->tail;
	}
	return (FT_OK);
}
