/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:57:57 by hbally            #+#    #+#             */
/*   Updated: 2019/01/11 18:49:57 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dirent.h"

void				ft_list_dir(char *name)
{
	DIR				*dir_to_parse;
	struct dirent	*dirent;

	dir_to_parse = opendir(name);

	if (dir_to_parse)
	{
		while ((dirent = readdir(dir_to_parse)))
			ft_putendl(dirent->d_name);
		closedir(dir_to_parse);
	}
}
