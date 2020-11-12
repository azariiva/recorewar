/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_queue.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:11:24 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/07 18:39:55 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_QUEUE_H

# define LIBFT_QUEUE_H

# include "libft_dlist.h"
# include "libft_list.h"
# include <stddef.h>

# ifndef E_RCODE

#  define E_RCODE

enum
{
	FT_ERR = -1,
	FT_OK = 1,
	FT_END = 0
};

# endif

typedef struct	s_queue
{
	t_list	*head;
	t_list	*tail;
}				t_queue;

/*
** T is datatype
** q is queue
*/
# define FT_QUETAIL(T, q) (FT_LSTCONT(T, (q)->tail))
# define FT_QUEHEAD(T, q) (FT_LSTCONT(T, (q)->head))

/*
** Allocates (with ft_memalloc) and returns a “fresh” queue. The head and tail
** of queue is initialized to ft_lstnew(content, content_size)
** If the allocation fails, the function returns NULL.
*/
t_queue			*ft_quenew(void const *content, size_t content_size);
/*
** Adds element new to the end of queue.
*/
int				ft_queadd(t_queue *queue, t_list *new);
int				ft_quevadd(t_queue *queue, void const *content,
size_t content_size);
/*
** Replaces head of the queue with the next element then returns the old head.
*/
t_list			*ft_quepop(t_queue *queue);
/*
** Takes as a paramemeter a queue's pointer address and frees the memory of the
** queue's head using the function ft_lstdel then frees the queue and sets
** recieved pointer to NULL.
*/
void			ft_quedel(t_queue **queue, void (*del)(void *, size_t));
/*
** Checks if queue is empty.
*/
int				ft_queisempty(t_queue *queue);

#endif
