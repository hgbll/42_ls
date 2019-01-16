/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:02:10 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 19:59:42 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char		get_type(uint16_t mode)
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

void		get_mode(struct stat *stats, t_printdata *data)
{
	uint16_t 		i;
	size_t			j;
	t_mode			mode;

	mode.raw = stats->st_mode;
	data->mode[0] = get_type(mode.bits.filetype);
	i = 0x100;
	j = 1;
//	ft_printf("i = %d, j = %d, mode = %s\n", i, j, data->mode);
	while (i > 0)
	{
		if (i & mode.bits.rights)
			data->mode[j] = data->symbols[j - 1 % 3];
		else
			data->mode[j] = '-';
		i /= 2;
		j++;
//		ft_printf("i = %d, j = %d, mode = %s\n", i, j, data->mode);
	}
	data->mode[j] = ' ';
}