/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quevadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:38:37 by fhilary           #+#    #+#             */
/*   Updated: 2020/08/16 14:54:24 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"
#include "libft_list.h"

int		ft_quevadd(t_queue *queue, void const *content, size_t content_size)
{
	if (!(ft_queadd(queue, content ? ft_lstnew(content, content_size)
	: ft_lstnew_ic(content_size))))
		return (FT_ERR);
	return (FT_OK);
}
