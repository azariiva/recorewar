/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_dlist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 01:50:52 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 15:16:06 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DLIST_H

# define LIBFT_DLIST_H

# include <stddef.h>

typedef struct	s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}				t_dlist;

t_dlist			*ft_dlstnew(void const *content, size_t content_size);
void			ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void			ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void			ft_dlstadd(t_dlist **alst, t_dlist *new);
void			ft_dlstiter_f(t_dlist *lst, void (*f)(t_dlist *elem));
void			ft_dlstiter_b(t_dlist *lst, void (*f)(t_dlist *elem));
t_dlist			*ft_dlstmap(t_dlist *lst, t_dlist *(f)(t_dlist *elem));
void			ft_dlstsort(t_dlist **dlst, int (*cmp)(t_dlist *, t_dlist *));

#endif
