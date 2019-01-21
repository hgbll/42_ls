/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:49:38 by hbally            #+#    #+#             */
/*   Updated: 2019/01/21 11:48:49 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "libft.h"

static int8_t		print_line(struct stat *stats, t_printdata *data,
								char *name)
{
	int8_t			status;

	if (data->oname && data->gname)
		status = ft_printf("%s %*d %-*s %-*s %s %s %s%s%s\n",
							data->mode,
							data->pad.links, stats->st_nlink,
							data->pad.oname, data->oname,
							data->pad.gname, data->gname,
							data->size, data->time, name,
							data->type == 'l' ? " -> " : "",
							data->type == 'l' ? data->target : "");
	else
		status = ft_printf("%s %*d %-*d %-*d %s %s %s%s%s\n",
						data->mode,
						data->pad.links, stats->st_nlink,
						data->pad.oname, stats->st_uid,
						data->pad.gname, stats->st_gid,
						data->size, data->time, name,
						data->type == 'l' ? " -> " : "",
						data->type == 'l' ? data->target : "");
	return (status);
}

static int8_t		print_entry_l(t_dirlist *dir, char *name, t_printdata *data)
{
	struct stat		stats;
	int8_t			status;

	ft_bzero(&stats, sizeof(struct stat));
	if ((status = get_stats(data->path, &stats, NOFOLLOW)))
		return (status);
	get_printdata(dir, &stats, data);
	status = print_line(&stats, data, name);
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
