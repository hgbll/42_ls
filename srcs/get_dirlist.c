/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:19:00 by hbally            #+#    #+#             */
/*   Updated: 2019/01/15 16:36:15 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ls.h"
#include "libft.h"

int8_t					get_dirlistlen(t_dirlist *dir)
{
	struct dirent			*entry;

	if (!(dir->dirp = opendir(dir->name)))
		return (exit_dir(dir, dir->name, DIR_ERR_OPEN, CUR_DIR_ERR));
	while ((entry = readdir(dir->dirp)))
		dir->len++;
//	ft_putstr("DIRLEN IS ");//
//	ft_putnbr(dir->len);//
//	ft_putstr("\n");//
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
//	ft_putstr("ALLOCATING DIRLIST : ");//
//	ft_putendl(dir->name);//
	dir->data = (t_entry*)ft_memalloc(sizeof(t_entry) * dir->len);
//	ft_putstr("FILLING DIRLIST : ");//
//	ft_putendl(dir->name);//
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
//	tmp_printdir(dir, dir->name);//
//	ft_putstr("FAILED TO ALLOCATE DIRLIST : ");//
//	ft_putendl(dir->name);//
	return (exit_dir(dir, dir->name, DIR_ERR_MALLOC, CUR_DIR_ERR));
}
