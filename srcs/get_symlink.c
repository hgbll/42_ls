/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:04:51 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:49:22 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/syslimits.h>
#include <unistd.h>
#include "libft.h"
#include "ls.h"

int8_t			get_symlink(t_printdata *data)
{
	ssize_t		status;

	if (data->type == 'l')
	{
		if ((data->target = ft_strnew(PATH_MAX)))
			status = readlink(data->path, data->target, PATH_MAX);
		else
			return (DIR_ERR_MALLOC);
	}
	return (0);
}
