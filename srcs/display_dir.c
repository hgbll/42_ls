/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:19:39 by hbally            #+#    #+#             */
/*   Updated: 2019/01/15 16:40:36 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "ls.h"

/*
**	Return values indicate program status :
**	0 	: OK
**	-- Error in current dir :
**  -1 	: Failed to open Dir or File -- Keep displaying / Print error
**	-2	: Malloc failure			 -- Stop displaying / Print error
**	-3	: closedir() failure		 -- Stop displaying / Print error
**	-- Error in subdir :
**  -4 	: Failed to open Dir or File -- Keep displaying / Don't print error
**	-5	: Malloc failure			 -- Stop displaying / Don't print error
**	-6	: closedir() failure		 -- Stop displaying / Don't print error
** (see header for macros)
*/

void					tmp_printdir(t_dirlist *dir, char *name)
{
		size_t i = 0;

//		ft_putstr("CONTENT OF DIR : ");
		if (dir->depth)
		{
			ft_putendl("");
			ft_putstr(name);
			ft_putendl(":");
		}
		while (i < dir->len)
		{
			ft_putendl(dir->data[i].name);
			i++;
		}
}

int8_t					exit_dir(t_dirlist *dir,
									char *name,
									int8_t status,
									int8_t origin)
{
	size_t				i;

	if (status < 0 && origin == CUR_DIR_ERR)
		error_handler(name, status);
	if (!dir->data && status == -2)
		str_error_handler("Data allocation failure", name, DIR_ERR_MALLOC);
	if (dir->data)
	{
		i = 0;
		while (i < dir->len)
		{
			if (dir->data[i].name)
				free(dir->data[i].name);
			else
				str_error_handler("Data allocation failure", name, DIR_ERR_MALLOC);
			i++;
		}
		free(dir->data);
		dir->data = NULL;
	}
	if (dir->depth > 0)
	{
		free(name);
		name = NULL;
	}
	return (status);
}

char				*makepath(t_dirlist *dir,
								char *to_add,
								size_t total_len,
								int8_t addslash)
{
	char			*path;

	path = ft_strnew(total_len);
	if (path)
	{
		ft_strcpy(path, dir->name);
		if (addslash)
			path[dir->namlen] = '/';
		ft_strcpy(&(path[dir->namlen + addslash]), to_add);
	}
	return (path);
}

int8_t				display_subdirs(t_dirlist *dir,
									t_entry *data,
									t_opt *opt)
{
	size_t			i;
	int8_t			status;
	uint32_t		pathlen;
	int8_t			addslash;

	i = 0;
	status = 0;
//	ft_putstr("READING SUBDIRS FROM : ");//
//	ft_putendl(dir->name);//
	addslash = dir->name[0] != '/' || dir->namlen != 1;
	while (i < dir->len)
	{
//		tmp_printdir(dir, dir->name);//
		if (dir->data[i].subdir)
		{
//			ft_putstr("ENTERING DIR : ");//
//			ft_putendl(data[i]->d_name);//
			pathlen = dir->namlen + ft_strlen(data[i].name) + addslash;
			status = display_dir(makepath(dir, data[i].name, pathlen, addslash),
									pathlen, opt, dir->depth + 1);
//			printf("Found dir, path : \n%s\n", makepath(dir, data[i]->d_name, pathlen));
			if (status < DIR_ERR_OPEN)
			{//
//					ft_putstr("FAILURE WHILE READING DIR : ");//
//					ft_putendl(dir->name);//
				return (status);
			}//
		}
//		else//
//		{//
//			ft_putstr("\t(IGNORING : ");
//			ft_putstr(data[i]->d_name);
//			ft_putstr(")\n");
//		}//
		i++;
	}
//	ft_putstr("FINISHED READING DIR : ");//
//	ft_putendl(dir->name);//
	return (status);
}

int8_t				display_dir(char *name,
								uint32_t namlen,
								t_opt *opt,
								size_t depth)
{
	t_dirlist		dir;
	int8_t			status;
	
//	ft_putstr("ENTERED DIR : ");//
//	ft_putendl(name);//
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
//	ft_putstr("EXITING DIR : ");//
//	ft_putendl(name);//
//	ft_putendl("");//
	return (exit_dir(&dir, name, status, SUB_DIR_ERR));
}
