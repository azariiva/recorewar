/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filefunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:36:31 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/03 17:40:55 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <limits.h>

int		isrighttype(char *name)
{
	return (!ft_strcmp(name + (ft_strlen(name) - 2), ".s"));
}

char	*new_filename(char *file, char *type)
{
	static char		filenew[PATH_MAX + 1];

	ft_bzero(filenew, sizeof(filenew));
	ft_strncpy(filenew, file, ft_strlen(file) - 2);
	ft_strcat(filenew, type);
	return (filenew);
}
