/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:19:39 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:34:49 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "libft.h"

void				display_container(t_dirlist *container, t_opt *opt)
{
	sort_dir(container, opt);
	print_dirlist(container, opt);
}

int8_t				display_subdirs(t_dirlist *dir, t_entry *data, t_opt *opt)
{
	size_t			i;
	int8_t			status;

	i = 0;
	status = 0;
	while (i < dir->len)
	{
		if (data[i].is_subdir)
		{
			status = display_dir(data[i].path, opt);
			if (status < DIR_ERR_OPEN)
				return (status);
		}
		i++;
	}
	return (status);
}

int8_t				display_dir(char *name, t_opt *opt)
{
	t_dirlist		dir;
	static uint64_t	counter;
	int8_t			status;

	if (opt->multi_arg || (opt->deep && counter != 0))
		ft_printf("%s%s:\n", counter > 0 ? "\n" : "", name);
	counter++;
	ft_bzero(&dir, sizeof(dir));
	dir.name = name;
	dir.namlen = (uint32_t)ft_strlen(name);
	if (!(status = get_dirlist(&dir, opt)) &&
		!(status = sort_dir(&dir, opt)) &&
		!(status = print_dirlist(&dir, opt)) &&
		opt->deep)
	{
		if ((status = display_subdirs(&dir, dir.data, opt)))
			return (exit_dir(&dir, name, status, ERR_NOPRINT));
	}
	return (exit_dir(&dir, name, status, ERR_PRINT));
}
