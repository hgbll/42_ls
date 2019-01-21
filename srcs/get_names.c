/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:00:36 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:56:57 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include "ls.h"
#include "libft.h"

int8_t		get_names(struct stat *stats, t_printdata *data)
{
	struct passwd	*pw;
	struct group	*grp;

	pw = getpwuid(stats->st_uid);
	grp = getgrgid(stats->st_gid);
	if (pw && pw->pw_name)
		data->ownername = pw->pw_name;
	if (grp && grp->gr_name)
		data->groupname = grp->gr_name;
	return (0);
}
