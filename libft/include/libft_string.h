/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:56:55 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/03 15:24:16 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H

# define LIBFT_STRING_H

# include <stddef.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
/*
** Allocates (with ft_memalloc) and returns an array of “fresh” strings (all
** ending with ’\0’, including the array itself) obtained by spliting s using
** the character c as a delimiter.
** If the allocation fails the function returns NULL. Example:
** ft_strsplit("*hello*fellow***students*", ’*’) returns the array ["hello",
** "fellow", "students"].
*/
char	**ft_strsplit(char const *s, char c);
/*
** Allocates (with ft_memalloc) and returns a “fresh” string end- ing with ’\0’.
** Each character of the string is initialized at ’\0’. If the allocation fails
** the function returns NULL.
*/
char	*ft_strnew(size_t size);
/*
** Takes as a parameter the address of a string that need to be freed with
** ft_memdel.
*/
void	ft_strdel(char **as);
/*
** Sets every character of the string to the value ’\0’.
*/
void	ft_strclr(char *s);
/*
** Applies the function f to each character of the string passed as argument.
** Each character is passed by address to f to be modified if necessary.
*/
void	ft_striter(char *s, void (*f)(char *));
/*
** Applies the function f to each character of the string passed as argument,
** and passing its index as first argument. Each character is passed by address
** to f to be modified if necessary.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/*
** The strchr() function returns a pointer to the first occurrence of the
** character c in the string s.
*/
char	*ft_strchr(const char *s, int c);
/*
** The strrchr() function returns a pointer to the last occurrence of the
** character c in the string s.
*/
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strccmp(const char *haystack, const char *needle, int c);
/*
** Allocates (with ft_memalloc) and returns an array of “fresh” strings (all
** ending with ’\0’, including the array itself) obtained by spliting s using
** the characters which satisfies function cmp as a delimiter.
** If the allocation fails the function returns NULL.
*/
char	**ft_strsplit_plus(char const *s, int (*cmp)(int));
/*
** The strchr_plus() function returns a pointer to the first occurrence of the
** character which satisfies function cmp.
*/
char	*ft_strchr_plus(const char *s, int (*cmp)(int));
void	ft_strup(char *tmp);

#endif
