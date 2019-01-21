/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:18:59 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:47:50 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include "ls.h"
#include "libft.h"

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
**	Get padding for device major and minor when in /dev
*/

static void			device_handler(t_dirlist *dir, t_printdata *data,
									struct stat *stats)
{
	dir->is_dev = 1;
	update_padding(NULL, (stats->st_rdev & 0xFF000000) >> 24,
						&(data->paddings.major));
	update_padding(NULL, stats->st_rdev & 0x00FFFFFF, &(data->paddings.minor));
}

/*
**	Note : get_padding also calculates total block count for -R option
*/

static void			add_whitespace(t_paddings *paddings)
{
	paddings->ownername += 1;
	paddings->size += 1;
	paddings->major += 2;
}

static void			get_namepadding(t_printdata *data, struct stat *stats)
{
	struct passwd	*pw;
	struct group	*grp;

	pw = getpwuid(stats->st_uid);
	grp = getgrgid(stats->st_gid);
	if (pw && pw->pw_name)
		update_padding(pw->pw_name, 0, &(data->paddings.ownername));
	if (grp && grp->gr_name)
		update_padding(grp->gr_name, 0, &(data->paddings.groupname));
}

int8_t				get_padding(t_dirlist *dir, t_printdata *data)
{
	size_t			i;
	struct stat		stats;
	int8_t			status;

	i = 0;
	while (i < dir->len)
	{
		ft_bzero(&stats, sizeof(struct stat));
		status = get_stats(dir->data[i].path, &stats, NOFOLLOW);
		if (!is_anchor(dir->data[i].name) &&
			(get_type(stats.st_mode) == 'd' || (status && dir->is_dev == 1)))
			dir->data[i].is_subdir = 1;
		if (get_type(stats.st_mode) == 'b' || get_type(stats.st_mode) == 'c')
			device_handler(dir, data, &stats);
		update_padding(NULL, (uint64_t)stats.st_size, &(data->paddings.size));
		update_padding(NULL, (uint64_t)stats.st_nlink, &(data->paddings.links));
		get_namepadding(data, &stats);
		data->total_blocks += stats.st_blocks;
		i++;
	}
	add_whitespace(&(data->paddings));
	return (0);
}
