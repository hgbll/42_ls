/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:49:38 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 20:45:41 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int8_t		print_entry_l(t_dirlist *dir, char *name, t_printdata *data)
{
	struct stat		stats;
	int8_t			status;

	get_stats_path(data->path, &stats, NOFOLLOW);
	get_printdata(dir, &stats, data);
	status = ft_printf("%s %*d %-*s %-*s %s %s %s%s%s\n",
						data->mode,
						data->paddings.links, stats.st_nlink,
						data->paddings.ownername, data->ownername,
						data->paddings.groupname, data->groupname,
						data->size, data->time, name,
						data->type == 'l' ? " -> " : "",
						data->type == 'l' ? data->target : "");
	free_printdata(data, 0);
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
