/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:03:36 by hbally            #+#    #+#             */
/*   Updated: 2019/01/17 14:04:46 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

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
