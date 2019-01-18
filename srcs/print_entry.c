/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:49:38 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 12:03:15 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int8_t		get_data(char *name, struct stat *stats, t_printdata *data)
{
	int8_t	status;

	ft_strcpy(data->symbols, "rwx");
	get_mode(stats, data);
	get_names(stats, data);
	if ((status = get_time(stats, data)) ||
		(status = get_names(stats, data)) ||
		(status = get_symlink(name, stats, data)))
		return (status);
	return (0);
}

static int8_t		print_entry_l(t_dirlist *dir, char *name, t_printdata *data)
{
	struct stat		stats;
	int8_t			status;

	if (get_stats(dir, name, &stats, NOFOLLOW) == DIR_ERR_OPEN ||
		get_data(name, &stats, data) == DIR_ERR_OPEN)
		return (DIR_ERR_OPEN);
	status = ft_printf("%s %*d %-*s %-*s %*llu %s %s%s\n",//
						data->mode,
						data->paddings.links, stats.st_nlink,
						data->paddings.ownername, data->ownername,
						data->paddings.groupname, data->groupname,
						data->paddings.size, stats.st_size,
						data->time,
						name,
						data->linkpath ? data->linkpath : "");
	if (data->linkpath)
		free(data->linkpath);
	return (status == -1 ? status : 0);
}

int8_t				print_entry(t_dirlist *dir, char *name, t_printdata *data)
{
	if (data)
		return (print_entry_l(dir, name, data));
	else
	{
		if (ft_printf("%s\n", name) == -1)
			return (DIR_ERR_PRINT);
		return (0);
	}
}
