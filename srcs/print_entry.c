/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:49:38 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 20:23:18 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int8_t		get_data(char *name, struct stat *stats, t_printdata *data)
{
	int8_t	status;

	//TEMPORARY
	data->symbols = ft_strnew(100);
	ft_strcpy(data->symbols, "rwx");
	data->mode = ft_strnew(100);
	data->time = ft_strnew(100);
	//
	get_mode(stats, data);
	get_names(stats, data);
	if ((status = get_time(stats, data)) ||
		(status = get_names(stats, data)) ||
		(status = get_symlink(name, stats, data)))
		return (status);
	return (0);
}

int8_t				print_entry_l(char *name, t_printdata *data)
{
	struct stat		stats;
	int8_t			status;

	if (lstat(name, &stats) == STAT_RET_ERR ||
		get_data(name, &stats, data) == STAT_RET_ERR)
		return (STAT_RET_ERR);
	status = ft_printf("%s %*d %-*s%-*s%*llu %s %s%s\n",
						data->mode,
						data->paddings.links, stats.st_nlink,
						data->paddings.ownername, data->ownername,
						data->paddings.groupname, data->groupname,
						data->paddings.size, stats.st_size,
						data->time,
						name,
						data->linkpath ? data->linkpath : "");
	if (data->linkpath)
		free(data->linkpath); // and other mallocs
	return (status);
}

int8_t				print_entry(char *name)
{
	if (ft_printf("%s\n", name) == -1)
		return (DIR_ERR_PRINT);
	return (0);
}
