/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:00:36 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 18:16:37 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t		get_names(struct stat *stats, t_printdata *data)
{
	struct passwd	*pw;
	struct group	*grp;

	if	(!(pw = getpwuid(stats->st_uid)) || !(grp = getgrgid(stats->st_gid)))
		return (DIR_ERR_OPEN);
	data->ownername = pw->pw_name;
	data->groupname = grp->gr_name;
	return (0);
}
