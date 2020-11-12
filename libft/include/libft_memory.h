/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:21:51 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/08 18:45:56 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H

# define LIBFT_MEMORY_H

# include <stddef.h>

typedef unsigned long int	ft_op;

# ifdef OPSIZ

#  undef OPSIZ

# endif

# define OPSIZ (sizeof(ft_op))

/*
** The ft_memset() function writes len bytes of value c (converted to an
** unsigned char) to the string b
*/
void			*ft_memset(void *b, int c, size_t len);
/*
** Allocates (with malloc()) and returns a “fresh” memory area. The memory
** allocated is initialized to 0. If the allocation fails, the function returns
** NULL.
*/
void			*ft_memalloc(size_t size);
/*
** Takes as a parameter the address of a memory area that needs to be freed with
** free(), then puts the pointer to NULL.
*/
void			ft_memdel(void **ap);
/*
** The ft_memcpy() function copies n bytes from memory area src to memory area
** dst. If dst and src overlap, behavior is undefined.  Applications in which
** dst and src might overlap should use ft_memmove() instead.
*/
void			*ft_memcpy(void *dst, const void *src, size_t n);
/*
** The ft_memccpy() function copies bytes from string src to string dst.  If the
** character c (as converted to an unsigned char) occurs in the string src, the
** copy stops and a pointer to the byte after the copy of c in the string dst is
** returned.  Otherwise, n bytes are copied, and a NULL pointer is returned.
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
*/
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
/*
** The ft_memmove() function copies len bytes from string src to string dst. The
** two strings may overlap; the copy is always done in a non-destructive manner.
*/
void			*ft_memmove(void *dst, const void *src, size_t len);
/*
** The ft_memchr() function locates the first occurrence of c (converted to an
** unsigned char) in string s.
*/
void			*ft_memchr(const void *s, int c, size_t n);
/*
** The ft_memcmp() function compares byte string s1 against byte string s2. Both
** strings are assumed to be n bytes long.
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_memccmp(const void *haystack, const void *needle, int c,
size_t n);
/*
** The ft_bzero() function writes n zeroed bytes to the string s.  If n is zero,
** ft_bzero() does nothing.
*/
void			ft_bzero(void *s, size_t n);

#endif
