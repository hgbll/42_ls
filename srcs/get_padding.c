/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:18:59 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 12:01:41 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

//block size is a uint64_t

static void			update_padding(char *str, uint64_t n, uint16_t *current)
{
	uint16_t		len;

	if (str)
		len = (uint16_t)ft_strlen(str);
	else
	{
		len = 1;
		if (n != 0)
		{
			while ((n /= 10) > 0)
				len++;
		}
	}
	if (len > *current)
		*current = len;
}

/*
**	Note : get_padding also calculates total block count for -R option
*/

static void			add_whitespace(t_paddings *paddings)
{
	paddings->ownername += 1;
	paddings->size += 1;
}

int8_t				get_padding(t_dirlist *dir, t_printdata *data)
{
	size_t			i;
	struct stat		stats;
	struct passwd	*pw;
	struct group	*grp;

	i = 0;
	while (i < dir->len)
	{
		if (get_stats(dir, dir->data[i].name, &stats, NOFOLLOW) ||
			!(pw = getpwuid(stats.st_uid)) ||
			!(grp = getgrgid(stats.st_gid)))
			return (DIR_ERR_OPEN);
		update_padding(NULL, (uint64_t)stats.st_nlink, &(data->paddings.links));
		update_padding(NULL, (uint64_t)stats.st_size, &(data->paddings.size));
		update_padding(pw->pw_name, 0, &(data->paddings.ownername));
		update_padding(grp->gr_name, 0, &(data->paddings.groupname));
		data->total_blocks += stats.st_blocks;
		i++;
	}
	add_whitespace(&(data->paddings));
	return (0);
}
