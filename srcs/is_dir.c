/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:21 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:25:37 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t					is_dir_deep(t_entry *entry)
{
	struct stat			stats;
	DIR					*dirp;

	if ((dirp = opendir(entry->path)))
	{
		if (!get_stats(entry->path, &stats, NOFOLLOW))
			if (get_type(stats.st_mode) == 'l')
			{
				closedir(dirp);
				return (0);
			}
		closedir(dirp);
		return (1);
	}
	return (0);
}

void					is_dir(t_arg *arg, t_opt *opt)
{
	struct stat			stats;
	uint8_t				is_dir;
	DIR					*dirp;

	is_dir = 0;
	if ((dirp = opendir(arg->path)))
	{
		is_dir = 1;
		closedir(dirp);
	}
	if (!get_stats(arg->path, &stats, NOFOLLOW))
		arg->type = get_type(stats.st_mode);
	else
	{
		arg->type = 0;
		arg->errno_value = errno;
	}
	if (is_dir && !(arg->type == 'l' && opt->ldisp))
		arg->type = 'd';
}
