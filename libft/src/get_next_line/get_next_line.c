/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:26:01 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/22 15:49:14 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_get_next_line.h"
#include "libft_list.h"
#include "libft_string.h"
#include <sys/types.h>
#include <unistd.h>

static char	*list_to_str(t_list **list)
{
	size_t	len;
	t_list	*ptr;
	char	*str;

	ptr = *list;
	len = 0;
	while (ptr)
	{
		len += ptr->content_size;
		ptr = ptr->next;
	}
	if ((str = ft_strnew(len + 1)))
	{
		ptr = *list;
		while (ptr)
		{
			ft_strncat(str, ptr->content, ptr->content_size);
			ptr = ptr->next;
		}
	}
	ft_lstdel(list, gnl_strdel);
	return (str);
}

static int	read_strlst(t_list *fdlst, t_list **strlst, char **line, \
		char *buff)
{
	t_list	*ptr;
	char	*end_gnllloc;
	ssize_t	len;

	ptr = *strlst;
	while (1)
	{
		if ((end_gnllloc = ft_strchr(ptr->content, '\n')))
		{
			*end_gnllloc++ = 0;
			if (*end_gnllloc && !(fdlst->content = ft_lstnew(end_gnllloc, \
							sizeof(char) * (ptr->content_size - (end_gnllloc - \
									(char *)ptr->content)))))
				return (FT_ERR);
			ptr->content_size = end_gnllloc - (char *)ptr->content;
			break ;
		}
		if (!(len = read(fdlst->content_size, buff, BUFF_SIZE)))
			break ;
		buff[len] = 0;
		if (!(ptr->next = ft_lstnew(buff, sizeof(char) * (len + 1))))
			return (FT_ERR);
		ptr = ptr->next;
	}
	return ((*line = list_to_str(strlst)) ? FT_OK : FT_ERR);
}

static int	read_fdlst(t_list *fdlst, char **line)
{
	t_list	*strlst;
	char	buff[BUFF_SIZE + 1];
	ssize_t	len;
	int		res;

	if (!(strlst = (t_list *)fdlst->content))
	{
		if ((len = read(fdlst->content_size, buff, BUFF_SIZE)) <= 0)
			return (len == 0 ? FT_END : FT_ERR);
		buff[len] = 0;
		if (!(strlst = ft_lstnew(buff, sizeof(char) * (len + 1))))
			return (FT_ERR);
	}
	fdlst->content = NULL;
	if ((res = read_strlst(fdlst, &strlst, line, buff)) == FT_ERR)
		ft_lstdel(&strlst, gnl_strdel);
	return (res);
}

int			lstdelandend(t_list **fdlst)
{
	ft_lstdel(fdlst, gnl_fddel);
	return (FT_END);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*fdlst;
	t_list			*ptr;
	int				res;

	if (fd == -1)
		return (lstdelandend(&fdlst));
	ptr = fdlst;
	while (ptr)
	{
		if (ptr->content_size == (size_t)fd)
		{
			if ((res = read_fdlst(ptr, line)) == FT_ERR)
				ptr->content = NULL;
			return (res);
		}
		ptr = ptr->next;
	}
	if (!(ptr = ft_lstnew_ic(fd)))
		return (FT_ERR);
	ft_lstadd(&fdlst, ptr);
	if ((res = read_fdlst(fdlst, line)) == FT_ERR)
		fdlst->content = NULL;
	return (res);
}
