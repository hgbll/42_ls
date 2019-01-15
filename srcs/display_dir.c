/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:19:39 by hbally            #+#    #+#             */
/*   Updated: 2019/01/14 20:22:43 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ls.h"

void					tmp_printdir(t_dirlist *dir, char *name)
{
		size_t i = 0;

		ft_putstr("CONTENT OF DIR : ");
		ft_putstr(name);
		ft_putendl("");
		while (i < dir->len)
		{
			if(ft_strcmp(dir->data[i]->d_name, ".") &&
				ft_strcmp(dir->data[i]->d_name, ".."))
				ft_putendl(dir->data[i]->d_name);
			i++;
		}
		ft_putendl("____________");

}
int8_t					exit_dir(t_dirlist *dir,
									char *name,
									int8_t status)
{
	if (status < 0)
		error_handler(name, status);
	if (dir->data)
	{
		free(dir->data);
		dir->data = NULL;
	}
	else
//		str_error_handler("Failed to allocate directory data.", name, -2);
	if (dir->depth > 0)
	{
		free(name);
		name = NULL;
	}
	return (status);
}

char				*makepath(t_dirlist *dir, char *to_add, size_t total_len)
{
	char			*path;
	
	path = ft_strnew(total_len);
	if (path)
	{
		ft_strcpy(path, dir->name);
		path[dir->namlen] = '/';
		ft_strcpy(&(path[dir->namlen + 1]), to_add);
	}
	return (path);
}

int8_t				display_subdirs(t_dirlist *dir,
									struct dirent **data,
									t_opt *opt)
{
	size_t			i;
	int8_t			status;
	uint32_t		pathlen;

	i = 0;
	status = 0;
	ft_putstr("READING SUBDIRS FROM : ");//
	ft_putendl(dir->name);//
	while (i < dir->len)
	{
		tmp_printdir(dir, dir->name);
		if (data[i]->d_type == DT_DIR && 
				ft_strcmp(data[i]->d_name, ".") &&
				ft_strcmp(data[i]->d_name, ".."))
		{
			ft_putstr("ENTERING DIR : ");//
			ft_putendl(data[i]->d_name);//
			pathlen = dir->namlen + data[i]->d_namlen + 1;
			status = display_dir(makepath(dir, data[i]->d_name, pathlen),
									pathlen, opt, dir->depth + 1);
//			printf("Found dir, path : \n%s\n", makepath(dir, data[i]->d_name, pathlen));
			if (status == -2)
			{//
					ft_putstr("FAILURE WHILE READING DIR : ");//
					ft_putendl(dir->name);//
				return (status);
			}//
		}
		else//
		{//
			ft_putstr("\t(IGNORING : ");
			ft_putstr(data[i]->d_name);
			ft_putstr(")\n");
		}//
		i++;
	}
	ft_putstr("FINISHED READING DIR : ");//
	ft_putendl(dir->name);//
	return (status);
}

int8_t				display_dir(char *name,
								uint32_t namlen,
								t_opt *opt,
								size_t depth)
{
	t_dirlist		dir;
	int8_t			status;
	
	ft_putstr("ENTERED DIR : ");//
	ft_putendl(name);//
	ft_bzero(&dir, sizeof(dir));
	dir.name = name;
	dir.namlen = namlen;
	dir.depth = depth;
	status = get_dirlist(&dir);
	if (status)
		return (status);
	if (dir.data)
	{
		/* debug */
//		sort_dir(&dir, opt);
//		print_dir(&dir, opt);
		tmp_printdir(&dir, name);
		if (opt->deep)
			status = display_subdirs(&dir, dir.data, opt);
	}
	ft_putstr("EXITING DIR : ");//
	ft_putendl(name);//
	ft_putendl("");//
	return (exit_dir(&dir, name, status));
}
