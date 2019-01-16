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

static int8_t			fill_dirlist(t_dirlist *dir, t_opt *opt)
{
	struct dirent		*entry;
	size_t				index;

	index = 0;
	while ((entry = readdir(dir->dirp)) && index < dir->len)
	{
		if (!is_hidden(entry->d_name, opt))
		{
			if ((dir->data[index].name = ft_strnew(entry->d_namlen)) == NULL)
				return (DIR_ERR_MALLOC);
			ft_strcpy(dir->data[index].name, entry->d_name);
			if (entry->d_type == DT_DIR && !is_anchor(entry->d_name))
				dir->data[index].subdir = 1;
			index++;
		}
	}
	if (index != dir->len)
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
		if ((status = fill_dirlist(dir, opt)) != 0)
			return (status);
		if (closedir(dir->dirp) == -1)
			return (DIR_ERR_CLOSE);
		return (0);
	}
	return (DIR_ERR_MALLOC);
}
