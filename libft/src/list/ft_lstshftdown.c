/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshftdown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:00:52 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 20:26:55 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_lstshftdown(t_list **lst)
{
	t_list	*bot;

	if (lst && *lst && (*lst)->next)
	{
		bot = ft_lstpopbot(lst);
		ft_lstadd(lst, bot);
	}
}
