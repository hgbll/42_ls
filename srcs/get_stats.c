/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:03:36 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 18:50:55 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t			get_stats_path(char *path, struct stat *stats,
								uint8_t nofollow)
{
	int8_t		status;

	if (nofollow)
		status = lstat(path, stats);
	else
		status = stat(path, stats);
	return (status);
}

int8_t			get_stats(t_dirlist *dir, char *name, struct stat *stats,
							uint8_t nofollow)
{
	char		*path;
	int8_t		status;

	path = mkpath(dir, name);
	if (!path)
		return (DIR_ERR_MALLOC);
	if (nofollow)
		status = lstat(path, stats);
	else
		status = stat(path, stats);
	ft_memdel((void**)&(path));
	return (status);
}
