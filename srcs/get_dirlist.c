/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:19:00 by hbally            #+#    #+#             */
/*   Updated: 2019/01/15 17:06:10 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t					get_dirlistlen(t_dirlist *dir)
{
	struct dirent			*entry;

	if (!(dir->dirp = opendir(dir->name)))
		return (exit_dir(dir, dir->name, DIR_ERR_OPEN, CUR_DIR_ERR));
	while ((entry = readdir(dir->dirp)))
		dir->len++;
	if (closedir(dir->dirp) == -1)
		return (exit_dir(dir, dir->name, DIR_ERR_CLOSE, CUR_DIR_ERR));
	return (0);
}

int8_t					fill_dirlist(t_dirlist *dir)
{
	struct dirent		*entry;
	size_t				index;

	index = 0;
	while ((entry = readdir(dir->dirp)))
	{
		if ((dir->data[index].name = ft_strnew(entry->d_namlen)) == NULL)
			return (exit_dir(dir, dir->name, DIR_ERR_MALLOC, CUR_DIR_ERR));
		ft_strcpy(dir->data[index].name, entry->d_name);
		if (entry->d_type == DT_DIR &&
				ft_strcmp(entry->d_name, ".") &&
				ft_strcmp(entry->d_name, ".."))
			dir->data[index].subdir = 1;
		index++;
	}
	return (0);
}

int8_t					get_dirlist(t_dirlist *dir)
{
	int8_t				status;

	if ((status = get_dirlistlen(dir)) != 0)
		return (status);
	dir->data = (t_entry*)ft_memalloc(sizeof(t_entry) * dir->len);
	if (dir->data)
	{
		if (!(dir->dirp = opendir(dir->name)))
			return (exit_dir(dir, dir->name, DIR_ERR_OPEN, CUR_DIR_ERR));
		if ((status = fill_dirlist(dir)) != 0)
			return (status);
		if (closedir(dir->dirp) == -1)
			return (exit_dir(dir, dir->name, DIR_ERR_CLOSE, CUR_DIR_ERR));
		return (0);
	}
	return (exit_dir(dir, dir->name, DIR_ERR_MALLOC, CUR_DIR_ERR));
}
