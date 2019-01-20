/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:02:10 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:25:10 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

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

static int8_t		get_xattr(t_printdata *data)
{
	if (listxattr(data->path, NULL, 0, XATTR_NOFOLLOW) > 0)
	{
		data->mode[10] = '@';
		return (1);
	}
	return (0);
}

static int8_t		get_acl(t_printdata *data)
{
	acl_t			acl;

	if ((acl = acl_get_link_np(data->path, ACL_TYPE_EXTENDED)))
	{
		data->mode[10] = '+';
		acl_free(acl);
		return (1);
	}
	return (0);
}

static void			set_bit(t_printdata *data, size_t index, t_mode *mode)
{
	if ((index == 2 && (mode->bits.extra & 4)) ||
		(index == 5 && (mode->bits.extra & 2)))
		data->mode[index + 1] = 's';
	else if (index == 8 && (mode->bits.extra & 1))
		data->mode[index + 1] = 't';
	else if (index % 3 == 0)
		data->mode[index + 1] = 'r';
	else if (index % 3 == 1)
		data->mode[index + 1] = 'w';
	else if (index % 3 == 2)
		data->mode[index + 1] = 'x';
}

int8_t				get_mode(struct stat *stats, t_printdata *data)
{
	uint16_t		i;
	size_t			j;
	t_mode			mode;

	mode.raw = stats->st_mode;
	data->type = get_type(mode.raw);
	data->mode[0] = data->type;
	i = 0x100;
	j = 1;
	while (i > 0)
	{
		if (i & mode.bits.rights)
			set_bit(data, j - 1, &mode);
		else
			data->mode[j] = '-';
		i /= 2;
		j++;
	}
	if (!get_xattr(data))
		if (!get_acl(data))
			data->mode[10] = ' ';
	data->mode[11] = '\0';
	return (0);
}
