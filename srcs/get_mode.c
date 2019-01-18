/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:02:10 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 18:32:19 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int8_t		get_xattr(t_printdata *data)
{
	ssize_t			status;

	status = listxattr(data->path, NULL, 0, XATTR_NOFOLLOW);
	if (status > 0)
		data->mode[10] = '@';
	else
		data->mode[10] = ' ';
	if (status == -1)
		return (error_handler(NULL, DIR_ERR_OPEN));
	return (0);
}

char				get_type(uint16_t mode)
{
	mode &= 0xF000;
	if (mode == S_IFREG)
		return ('-');
	else if (mode == S_IFDIR)
		return ('d');
	else if (mode == S_IFLNK)
		return ('l');
	else if (mode == S_IFIFO)
		return ('p');
	else if (mode == S_IFSOCK)
		return ('s');
	else if (mode == S_IFCHR)
		return ('c');
	else if (mode == S_IFBLK)
		return ('b');
	else if (mode == S_IFWHT)
		return ('w');
	else
		return ('-');
}

int8_t				get_mode(struct stat *stats, t_printdata *data)
{
	uint16_t 		i;
	size_t			j;
	t_mode			mode;
	int8_t			status;

	mode.raw = stats->st_mode;
	data->type = get_type(mode.raw);
	data->mode[0] = data->type;
	i = 0x100;
	j = 1;
	while (i > 0)
	{
		if (i & mode.bits.rights)
			data->mode[j] = data->symbols[(j - 1) % 3];
		else
			data->mode[j] = '-';
		i /= 2;
		j++;
	}
	status = get_xattr(data);
	data->mode[11] = '\0';
	return (status);
}
