/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:19:00 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 19:49:58 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static uint8_t			is_dir(t_entry *entry)
{
	struct stat			stats;
	DIR					*dirp;

	if (!get_stats_path(entry->path, &stats, NOFOLLOW))
	{
//		ft_printf("Looking at : %s\n", entry->path);
//		if ((dirp = opendir(entry->path)))
//			ft_printf("Can open %s\n", entry->name);
//		if (get_type(stats.st_mode) != 'l')
//			ft_printf("%s is not a link\n", entry->name);
//		if (!is_anchor(entry->name))
//			ft_printf("%s is not an anchor\n", entry->name);
		if ((dirp = opendir(entry->path)) &&
			get_type(stats.st_mode) != 'l' &&
			!is_anchor(entry->name))
		{
			return (1);
		}
	}
	return (0);
}

static int8_t			get_dirlistlen(t_dirlist *dir, t_opt *opt)
{
	struct dirent			*entry;

	if (!(dir->dirp = opendir(dir->name)))
		return (DIR_ERR_OPEN);
	while ((entry = readdir(dir->dirp)))
		if (!is_hidden(entry->d_name, opt))
			dir->len++;
	if (closedir(dir->dirp) == -1)
		return (DIR_ERR_CLOSE);
	return (0);
}

static int8_t			fill_dirlist(t_dirlist *dir, t_entry *data, t_opt *opt)
{
	struct dirent		*entry;
	size_t				i;

	i = 0;
	while ((entry = readdir(dir->dirp)) && i < dir->len)
	{
		if (!is_hidden(entry->d_name, opt))
		{
			if (!(data[i].path = mkpath(dir, entry->d_name)))
				return (DIR_ERR_MALLOC);
			data[i].name = ft_strrchr(data[i].path, '/') + 1;
			data[i].is_subdir = is_dir(&(data[i]));
			i++;
		}
	}
	if (i != dir->len)
		return (DIR_ERR_OPEN);
	return (0);
}

int8_t					get_dirlist(t_dirlist *dir, t_opt *opt)
{
	int8_t				status;

	if ((status = get_dirlistlen(dir, opt)) != 0)
		return (status);
	dir->data = (t_entry*)ft_memalloc(sizeof(t_entry) * dir->len);
	if (dir->data)
	{
		if (!(dir->dirp = opendir(dir->name)))
			return (DIR_ERR_OPEN);
		if ((status = fill_dirlist(dir, dir->data, opt)) != 0)
			return (status);
		if (closedir(dir->dirp) == -1)
			return (DIR_ERR_CLOSE);
		return (0);
	}
	return (DIR_ERR_MALLOC);
}
