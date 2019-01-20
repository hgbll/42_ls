/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:03:13 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:35:54 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "libft.h"

static int8_t		print_loop(t_dirlist *dir, t_printdata *printdata)
{
	size_t			i;
	int8_t			status;

	i = 0;
	while (i < dir->len)
	{
		if (printdata)
		{
			printdata->path = dir->data[i].path;
			printdata->name = dir->data[i].name;
		}
		status = print_entry(dir, dir->data[i].name, printdata);
		if (status < DIR_ERR_OPEN)
			return (status);
		i++;
	}
	return (0);
}

static int8_t		print_dirlist_l(t_dirlist *dir)
{
	t_printdata		printdata;

	ft_bzero(&printdata, sizeof(t_printdata));
	get_padding(dir, &printdata);
	if (!dir->is_container)
		if (ft_printf("total %llu\n", printdata.total_blocks) == -1)
			return (DIR_ERR_PRINT);
	return (print_loop(dir, &printdata));
}

int8_t				print_dirlist(t_dirlist *dir, t_opt *opt)
{
	if (opt->ldisp && dir->len > 0)
		return (print_dirlist_l(dir));
	else
		return (print_loop(dir, NULL));
}
