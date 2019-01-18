/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:04:51 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 19:08:43 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t			get_symlink(t_printdata *data)
{
	ssize_t		status;

	if (data->type == 'l')
	{
		if ((data->target = ft_strnew(PATH_MAX)))
		{
			status = readlink(data->path, data->target, PATH_MAX);
			return (status != -1 ? 0 : error_handler(NULL, DIR_ERR_OPEN));
		}
		return (DIR_ERR_MALLOC);
	}
	return (0);
}
