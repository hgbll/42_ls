/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:52:54 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:56:21 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "libft.h"

static void				free_dirlist(t_dirlist *dir)
{
	size_t				i;

	if (dir->data)
	{
		i = 0;
		while (i < dir->len)
		{
			if (dir->data[i].path)
				ft_memdel((void**)&(dir->data[i].path));
			i++;
		}
		ft_memdel((void**)&(dir->data));
	}
}

int8_t					exit_dir(t_dirlist *dir,
									char *name,
									int8_t status,
									int8_t print)
{
	if (status < 0 && print == ERR_PRINT)
		error_handler(name, status);
	free_dirlist(dir);
	return (status);
}
