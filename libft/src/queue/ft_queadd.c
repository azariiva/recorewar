/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:05:00 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/01 20:02:00 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"

int	ft_queadd(t_queue *queue, t_list *new)
{
	if (!new || !queue)
		return (FT_ERR);
	if (!queue->head)
	{
		queue->head = new;
		queue->tail = queue->head;
	}
	else
	{
		queue->tail->next = new;
		queue->tail = queue->tail->next;
	}
	return (FT_OK);
}
