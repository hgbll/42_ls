/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:47:25 by hbally            #+#    #+#             */
/*   Updated: 2019/01/11 19:40:21 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdint.h>
#include "libftprintf.h"
#include "libft.h"
#include "ft_inspect_file.h"

//DEBUG ONLY
#include <sys/xattr.h>

void		print_memory(void *p1, int nb_of_bytes)
{
	int i;
	int j;

	j = 0;
	while (j < nb_of_bytes)
	{
		ft_printf("%p	", (((unsigned char*)p1) + nb_of_bytes - 1  - j));
		j++;
	}
	ft_printf("\n");
	j = 0;
	while (j < nb_of_bytes)
	{
		i = 0x80;
		while (i > 0)
		{
			ft_printf("%d", ((int)*((unsigned char*)p1 + nb_of_bytes - 1 - j) & i) != 0);
			i /= 2;
		}
		ft_printf("	");
		j++;
	}
	ft_printf("\n---\n");
}

char				*get_type(unsigned short type)
{
	if (!(type ^ S_IFIFO))
		return ("Named Pipe");
	if (!(type ^ S_IFCHR))
		return ("Character Special");
	if (!(type ^ S_IFDIR))
		return ("Directory");
	if (!(type ^ S_IFBLK))
		return ("Block Special");
	if (!(type ^ S_IFREG))
		return ("File");
	if (!(type ^ S_IFLNK))
		return ("Symbolic Link");
	if (!(type ^ S_IFSOCK))
		return ("Socket");
	if (!(type ^ S_IFWHT))
		return ("Whiteout");
	return (NULL);
}

void				get_rights(unsigned short rights, char string[])
{
	unsigned short	i;
	size_t			j;

	i = 0x100;
	j = 0;
	while (i > 0)
	{
		if (i & rights)
		{
			if (j % 3 == 0)
				string[j] = 'r';
			else if (j % 3 == 1)
				string[j] = 'w';
			else
				string[j] = 'x';
		}
		else
			string[j] = '-';
		i /= 2;
		j++;
	}
	string[j] = '\0';
}

void				ft_inspect_file(char *name)
{
	struct stat			file_stats;
	t_printable_stats	stats_print;
	t_mode_flags		mode;

	stat(name, &file_stats);
	mode.mode = file_stats.st_mode;
	stats_print.name = name;
	ft_strcpy(stats_print.type, get_type(mode.flags.filetype << 12));
	get_rights(mode.flags.rights, stats_print.rights);
	stats_print.last_modified = ctime(&(file_stats.st_mtimespec.tv_sec));
	stats_print.last_modified = ft_strsub(stats_print.last_modified, 4, 12); // use a dedicated no-malloc sub function

	ft_printf("(Size of stat struct : %zu)\n", sizeof(struct stat));
	ft_printf("Nom: %s\n", stats_print.name);
	ft_printf("Type: %s\n", stats_print.type);
	ft_printf("Modes: %s\n", stats_print.rights);
	ft_printf("Nombre de liens: %d\n", file_stats.st_nlink);
	ft_printf("Proprietaire: %s\n", (getpwuid(file_stats.st_uid))->pw_name);
	ft_printf("Groupe: %s\n", (getgrgid(file_stats.st_gid)->gr_name));
	ft_printf("Taille: %lld octets\n", file_stats.st_size);
	ft_printf("Date de derniere modification: %s\n", stats_print.last_modified);
}
