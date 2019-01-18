/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:19:39 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 11:58:52 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int8_t		display_subdirs(t_dirlist *dir, t_entry *data, t_opt *opt)
{
	size_t			i;
	int8_t			status;

	i = 0;
	status = 0;
	while (i < dir->len)
	{
		if (data[i].subdir)
		{
			status = display_dir(mkpath(dir, data[i].name), opt,
									dir->depth + 1);
			if (status < DIR_ERR_OPEN)
				return (status);
		}
		i++;
	}
	return (status);
}

int8_t				display_dir(char *name, t_opt *opt, size_t depth)
{
	t_dirlist		dir;
	int8_t			status;
	
	ft_bzero(&dir, sizeof(dir));
	dir.name = name;
	dir.namlen = (uint32_t)ft_strlen(name);
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
