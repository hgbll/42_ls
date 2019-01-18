/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:00:36 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 19:48:31 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t		get_names(struct stat *stats, t_printdata *data)
{
	struct passwd	*pw;
	struct group	*grp;

	pw = getpwuid(stats->st_uid);
	grp = getgrgid(stats->st_gid);
	if (pw && pw->pw_name)
		data->ownername = pw->pw_name;
	else
	{
		data->ownername = ft_ulltoa((uint64_t)stats->st_uid);
		data->no_ownername = 1;
	}
	if (grp && grp->gr_name)
		data->groupname = grp->gr_name;
	else
	{
		data->groupname = ft_ulltoa((uint64_t)stats->st_gid);
		data->no_groupname = 1;
	}
	return (0);
}
