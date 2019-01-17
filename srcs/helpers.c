/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:05:45 by hbally            #+#    #+#             */
/*   Updated: 2019/01/17 18:00:36 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

uint8_t					is_anchor(char *name)
{
	if (!ft_strcmp(name, ".") || !ft_strcmp(name, ".."))
		return (1);
	else
		return (0);
}

uint8_t					is_hidden(char *name, t_opt *opt)
{
	if (name[0] == '.' && !opt->nohide)
		return (1);
	else
		return (0);
}

char				*path(t_dirlist *dir, char *to_add)
{
	char			*path;

	if (dir->name[0] != '/' || dir->namlen != 1)
		ft_asprintf(&path, "%s/%s", dir, to_add);
	else
		ft_asprintf(&path, "%s%s", dir, to_add);
	return (path);
}
