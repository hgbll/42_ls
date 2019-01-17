/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:52:54 by hbally            #+#    #+#             */
/*   Updated: 2019/01/17 17:57:18 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void				free_dirlist(t_dirlist *dir,
										char *name,
										int8_t status)
{
	size_t 				i;

	if (!dir->data && status == -2)
		str_error_handler("Data allocation failure",
							name, DIR_ERR_MALLOC);
	if (dir->data)
	{
		i = 0;
		while (i < dir->len)
		{
			if (dir->data[i].name)
			{
				free(dir->data[i].name);
				dir->data[i].name = NULL;
			}
			else
				str_error_handler("Data allocation failure",
									name, DIR_ERR_MALLOC);
			i++;
		}
		free(dir->data);
		dir->data = NULL;
	}
}

int8_t					exit_dir(t_dirlist *dir,
									char *name,
									int8_t status,
									int8_t print)
{
	if (status < 0 && print == ERR_PRINT)
		error_handler(name, status);
	free_dirlist(dir, name, status);
	if (dir->depth > 0)
	{
		free(name);
		name = NULL;
	}
	return (status);
}
