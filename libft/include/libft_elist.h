/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_elist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:46:05 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/12 20:54:03 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ELIST_H

# define LIBFT_ELIST_H

# include "libft_dlist.h"
# include <stddef.h>

/*
** t_elist combines all functionality of t_queue and t_list with improved
** user experience
*/

# ifndef E_RCODE

#  define E_RCODE

enum
{
	FT_ERR = -1,
	FT_OK = 1,
	FT_END = 0
};

# endif

typedef struct	s_elist
{
	t_dlist		*head;
	t_dlist		*tail;
	size_t		content_size;
	void		(*del)(void *, size_t);
	t_dlist		*garbage;
}				t_elist;

t_elist			*ft_elistnew(size_t content_size, void (*del)(void *, size_t));
void			ft_elistdel(t_elist **elist);
int				ft_elistpushtop(t_elist *elist, void *content);
int				ft_elistpushbot(t_elist *elist, void *content);
void			*ft_elistpoptop(t_elist *elist);
void			*ft_elistpopbot(t_elist *elist);

#endif
