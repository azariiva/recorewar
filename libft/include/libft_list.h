/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:39:42 by blinnea           #+#    #+#             */
/*   Updated: 2020/11/01 13:49:58 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H

# define LIBFT_LIST_H

# include <stddef.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** T is datatype
** l is list
*/
# define FT_LSTCONT(T, l) ((T *)((l)->content))

/*
** Allocates (with ft_memalloc) and returns a “fresh” link. The variables
** content and content_size of the new link are initialized by copy of the
** parameters of the function. If the parameter content is nul, the variable
** content is initialized to NULL and the variable content_size is initialized
** to 0 even if the parameter content_size isn’t. The variable next is
** initialized to NULL.
** If the allocation fails, the function returns NULL.
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
/*
** Allocates (with ft_memalloc) and returns a “fresh” link. The content_size
** of the new link are initialized by copy of the parameter of the function. The
** variable content is initialized to NULL. The variable next is initialized to
** NULL. If the allocation fails, the function returns NULL.
*/
t_list			*ft_lstnew_ic(size_t content_size);

/*
** Takes as a parameter a link’s pointer address and frees the memory of the
** link’s content using the function del given as a parameter, then frees the
** link’s memory using ft_memdel. Finally, the pointer to the link that was just
** freed sets to NULL.
*/
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
/*
** Takes as a parameter a link’s pointer address and doesn't free the memory of
** the link’s content, then frees the link’s memory using ft_memdel. Finally,
** the pointer to the link that was just freed set to NULL.
*/
void			ft_lstdelone_ic(t_list **alst);

/*
** Takes as a parameter the adress of a pointer to a link and frees the memory
** of this link and every successors of that link using the functions del and
** ft_lstdelone.
**  The pointer to the link that was just freed must be set to
** NULL.
*/
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
/*
** Takes as a parameter the adress of a pointer to a link and frees the memory
** of this link and every successors of that link using the function
** ft_lstdelone_ic ignoring content.
** Finally the pointer to the link that was just freed must be set to NULL.
*/
void			ft_lstdel_ic(t_list **alst);

/*
** Adds the element new at the beginning of the list.
*/
void			ft_lstadd(t_list **alst, t_list *new);
/*
** Adds the element new before the element e, where cmp(e, new) is true.
*/
void			ft_lstadd_sorted(t_list **alst, t_list *new,
								int (*cmp)(t_list *cur, t_list *new));
/*
** Iterates the list lst and applies the function f to each link.
*/
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
/*
** Iterates a list lst and applies the function f to each link to create a
** “fresh” list (using ft_memalloc) resulting from the successive
** applications of f. If the allocation fails, the function returns NULL.
*/
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
** Swaps top two elements of the list. Does nothing if there are one or less
** elements in the list.
*/
void			ft_lstswptop(t_list **lst);
/*
** Pops first element of the list. If the first element is unreachable returns
** NULL.
*/
t_list			*ft_lstpoptop(t_list **lst);
/*
** Pops last element of the list. If the last element is unreachable returns
** NULL.
*/
t_list			*ft_lstpopbot(t_list **lst);
/*
** Takes the first element at the top of src and put it at the top of dst. Do
** nothing if src is empty.
*/
void			ft_lsttrans(t_list **dst, t_list **src);
/*
** Shifts up all elements of list a by 1. The first element becomes the last
** one.
*/
void			ft_lstshftup(t_list **lst);
/*
** Shifts down all elements of list a by 1. The last element becomes the first
** one.
*/
void			ft_lstshftdown(t_list **lst);
/*
** Calculates size of the stack
*/
size_t			ft_lstsize(t_list *lst);

#endif
