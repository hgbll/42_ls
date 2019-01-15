/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:19:00 by hbally            #+#    #+#             */
/*   Updated: 2019/01/14 20:21:26 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ls.h"
#include "libft.h"

int8_t					get_dirlistlen(t_dirlist *dir)
{
	struct dirent			*entry;

	if (!(dir->dirp = opendir(dir->name)))
		return (exit_dir(dir, dir->name, -1));
	while ((entry = readdir(dir->dirp)))
		dir->len++;
	ft_putstr("DIRLEN IS ");//
	ft_putnbr(dir->len);//
	ft_putstr("\n");//
	if (closedir(dir->dirp) == -1)
		return (error_handler(dir->name, -2));
	return (0);
}

int8_t					get_dirlist(t_dirlist *dir)
{
	struct dirent		*entry;
	int8_t				status;
	size_t				index;

	status = get_dirlistlen(dir);
	if (status)
		return (status);
	ft_putstr("ALLOCATING DIRLIST : ");
	ft_putendl(dir->name);
	dir->data = (struct dirent**)ft_memalloc(sizeof(struct dirent*) * dir->len);
	ft_putstr("FILLING DIRLIST : ");
	ft_putendl(dir->name);
	if (dir->data)
	{
		if (!(dir->dirp = opendir(dir->name)))
			return (exit_dir(dir, dir->name, -2));
		index = 0;
		while ((entry = readdir(dir->dirp)))
			dir->data[index++] = entry;
		if (closedir(dir->dirp) == -1)
			return (exit_dir(dir, dir->name, -2));
		return (0);
	}
	tmp_printdir(dir, dir->name);
	ft_putstr("FAILED TO ALLOCATE DIRLIST : ");
	ft_putendl(dir->name);
	return (exit_dir(dir, dir->name, -2));
}
