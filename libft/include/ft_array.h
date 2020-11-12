/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by rnugroho          #+#    #+#             */
/*   Updated: 2020/11/12 20:51:37 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stddef.h>
# include <stdlib.h>

# define _MIN2(A,B) ((A) < (B) ? (A) : (B))

typedef struct	s_array
{
	void		*data;
	size_t		size;
	size_t		max;
	size_t		type_size;
}				t_array;

# define NEW_ARRAY(T) (t_array){NULL, 0, 0, sizeof(T)}

t_array			fta_new(size_t type_size);
int				fta_append(t_array *self, void const *data, size_t datalen);
int				fta_append_free(t_array *self, void *data, size_t datalen);
int				fta_append_char(t_array *self, char data);
int				fta_insert(
				t_array *self, void const *data, size_t datalen, size_t index);
int				fta_reserve(t_array *self, size_t size);
int				fta_trim(t_array *self);
void			fta_popback(t_array *self, size_t len);
void			fta_popzero(t_array *self, int *ans);
void			fta_popzerohex(t_array *self, int *ans);
void			fta_popbackf(t_array *self, size_t len, void (*del)(void *));
int				fta_popindex(t_array *self, size_t index, size_t len);
int				fta_popindexf(
	t_array *self, size_t index, size_t len, void (*del)(void *));
int				fta_replace(
	t_array *self, size_t index, size_t len, t_array *new);

# define ARRAY_POPFRONT(A,N) fta_popindex(A, 0, N)
# define ARRAY_INDEX_CHECK(A,I) (0 <= (I) && (I) < (A)->size)
# define ARRAY_GET(A,I) (ARRAY_START(A) + ARRAY_OFFSET(A,I))
# define ARRAY_GETS(A,I) (ARRAY_INDEX_CHECK(A,I) ? ARRAY_GET(A,I) : NULL)
# define ARRAY_GETT(T,A,I) ((T*)ARRAY_GET(A,I))
# define ARRAY_GETTS(T,A,I) ((T*)ARRAY_GETS(A,I))
# define ARRAY_GETL(T,A,I) (*ARRAY_GETT(T,A,I))
# define ARRAY_IFP(A,P) ((((void *)P) - (A)->data) / (A)->type_size)
# define ARRAY_ITERATOR(A) (ARRAY_START(A) - ARRAY_STEP(A))
# define ARRAY_START(A) ((A)->data)
# define ARRAY_END(A) ((A)->data + (A)->size * (A)->type_size)
# define ARRAY_LAST(A) ((char *)((A)->data + (A)->size * (A)->type_size - 1))
# define ARRAY_STEP(A) ((A)->type_size)
# define ARRAY_OFFSET(A,I) ((I) * ARRAY_STEP(A))
# define ARRAY_NEXT(A,IT) ((IT) += ARRAY_STEP(A))
# define ARRAY_HASNEXT(A,IT) (ARRAY_NEXT(A,IT) < ARRAY_END(A))

char			*fta_string(t_array *self, char *(*f)(void *));

# define ARRAY_INITIAL_SIZE 16
# define ARRAY_FACTOR 2

int				fta_resize(t_array *self, size_t new_size);
void			fta_swap(t_array *self, size_t before, size_t after);
void			fta_clear(t_array *self);
void			fta_printdata_int(t_array *v);

#endif
