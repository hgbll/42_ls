/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printdata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:31:58 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 20:18:04 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t		free_printdata(t_printdata *data, int8_t status)
{
	if (data->target)
		ft_memdel((void**)&(data->target));
	if (data->size)
		ft_memdel((void**)&(data->size));
	if (data->no_ownername)
		ft_memdel((void**)&(data->ownername));
	if (data->no_groupname)
		ft_memdel((void**)&(data->groupname));
	return (status);
}

int8_t		get_printdata(t_dirlist *dir, struct stat *stats, t_printdata *data)
{
	int8_t	status;

	status = 0;//
	if (//!ft_printf("Fetching mode\n") ||//
		(status = get_mode(stats, data)) ||
		//!ft_printf("Fetching time\n") ||//
		(status = get_time(stats, data)) ||
		//!ft_printf("Fetching size\n") ||//
		(status = get_size(dir, stats, data)) ||
		//!ft_printf("Fetching names\n") ||//
		(status = get_names(stats, data)) ||
		//!ft_printf("Fetching link\n") ||//
		(status = get_symlink(data)))
		return (free_printdata(data, status));
	return (0);
}
