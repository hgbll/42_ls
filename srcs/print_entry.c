/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:49:38 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 15:46:40 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "ls_print.h"

int8_t				print_entry(char *name, t_print_data *data, t_opt *opt)
{
	struct stat		stats;
	int8_t			status;

	if (lstat(name, &stats) == STAT_RET_ERR ||
		print_getdata(&stats, data, opt) == STAT_RET_ERR)
		return (STAT_RET_ERR);
	if (opt->deep)
	{
		status = ft_printf("%s %*d %-*s%-*s%*llu %s %s%s\n",
							data->mode,
							data->paddings.links,
							stats.st_nlink,
							data->paddings.ownername,
							data->ownername,
							data->paddings.groupname,
							data->groupname,
							data->size_padding,
							stats.st_size,
							data->time,
							name,
							data->linkpath ? data->linkpath : "");
		if (data->linkpath)
			free(linkpath);
	}
	else
	{
		status = ft
	}
}
