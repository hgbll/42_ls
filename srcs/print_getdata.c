/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_getdata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:42:07 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 15:48:58 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "ls_print.h"

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

int8_t				get_time(struct stat *stats, t_print_data)
{
	stats_print.last_modified = ctime(&(file_stats.st_mtimespec.tv_sec));
	stats_print.last_modified = ft_strsub(stats_print.last_modified, 4, 12); // use a dedicated no-malloc sub function

}

int8_t				get_names()
	ft_printf("Proprietaire: %s\n", (getpwuid(file_stats.st_uid))->pw_name);
	ft_printf("Groupe: %s\n", (getgrgid(file_stats.st_gid)->gr_name));

void				get_mode(struct stat *stats, t_print_data *data)
{
	uint16_t 		i;
	size_t			j;
	t_mode			mode;

	mode.raw = stats->st_mode;
	data->mode[0] = get_type(mode.bits.filetype);
	i = 0x100;
	j = 1;
	while (i > 0)
	{
		if (i & mode.bits.rights)
			data->mode[j] = data->rights_symbols[j - 1 % 3];
		else
			string[j] = '-';
		i /= 2;
		j++;
	}
	data->mode[j] = ' ';
}

int8_t				print_
