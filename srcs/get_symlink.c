/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:04:51 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 17:33:50 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t			get_symlink(t_dirlist *dir, char *name, t_printdata *data)
{
	ssize_t		status;
	char		*path;

	if (data->type == 'l')
	{
		if ((data->target = ft_strnew(PATH_MAX)))
		{
			if ((path = mkpath(dir, name)))
			{
				status = readlink(path, data->target, PATH_MAX);
				ft_memdel((void**)&(path));
				return (status != -1 ? 0 : error_handler(NULL, DIR_ERR_OPEN));
			}
		}
		return (DIR_ERR_MALLOC);
	}
	return (0);
}
