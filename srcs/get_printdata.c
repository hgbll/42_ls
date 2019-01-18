/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printdata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:31:58 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 18:29:30 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t		free_printdata(t_printdata *data, int8_t status)
{
	if (data->path)
		ft_memdel((void**)&(data->path));
	if (data->target)
		ft_memdel((void**)&(data->target));
	if (data->size)
		ft_memdel((void**)&(data->size));
	return (status);
}

int8_t		get_printdata(t_dirlist *dir, struct stat *stats, t_printdata *data)
{
	int8_t	status;

	ft_strcpy(data->symbols, "rwx");
	if ((status = get_mode(stats, data)) ||
		(status = get_time(stats, data)) ||
		(status = get_size(dir, stats, data)) ||
		(status = get_names(stats, data)) ||
		(status = get_symlink(data)))
		return (free_printdata(data, status));
	return (0);
}
