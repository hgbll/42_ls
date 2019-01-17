/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:19:39 by hbally            #+#    #+#             */
/*   Updated: 2019/01/17 17:13:55 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int8_t		display_subdirs(t_dirlist *dir,
									t_entry *data,
									t_opt *opt)
{
	size_t			i;
	int8_t			status;
	uint32_t		pathlen;
	int8_t			addslash;

	i = 0;
	status = 0;
	addslash = dir->name[0] != '/' || dir->namlen != 1;
	while (i < dir->len)
	{
		if (dir->data[i].subdir)
		{
			pathlen = dir->namlen + ft_strlen(data[i].name) + addslash;
			status = display_dir(makepath(dir,
											data[i].name,
											pathlen,
											addslash),
									pathlen,
									opt,
									dir->depth + 1);
			if (status < DIR_ERR_OPEN)
				return (status);
		}
		i++;
	}
	return (status);
}

int8_t				display_dir(char *name,
								uint32_t namlen,
								t_opt *opt,
								size_t depth)
{
	t_dirlist		dir;
	int8_t			status;
	
	ft_bzero(&dir, sizeof(dir));
	dir.name = name;
	dir.namlen = namlen;
	dir.depth = depth;
	if (!(status = get_dirlist(&dir, opt)) &&
		!(status = sort_dir(&dir, opt)) &&
		!(status = print_dirlist(&dir, opt)) &&
		opt->deep)
	{
		if (!(status = display_subdirs(&dir, dir.data, opt)))
			return (exit_dir(&dir, name, status, ERR_NOPRINT));
	}
	return (exit_dir(&dir, name, status, ERR_PRINT));
}
