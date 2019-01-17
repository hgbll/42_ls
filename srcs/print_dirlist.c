/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:03:13 by hbally            #+#    #+#             */
/*   Updated: 2019/01/17 17:13:57 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int8_t		print_loop(t_dirlist *dir, t_printdata *printdata)
{
	size_t			i;
	int8_t			status;

	i = 0;
	while (i < dir->len)
	{
		if((status = print_entry(dir->data[i].name, printdata)))
			return (status);
		i++;
	}
	return (0);
}

static int8_t		print_dirlist_l(t_dirlist *dir)
{
	t_printdata		printdata;

	ft_bzero(&printdata, sizeof(t_printdata));
	if (get_padding(dir, &printdata))
		return (STAT_RET_ERR);
	if ((dir->depth != 0 && ft_printf("\n%s:\n", dir->name) != -1) ||
		(ft_printf("total %llu\n", printdata.total_blocks) != -1))
		return (print_loop(dir, &printdata));
	else
		return (DIR_ERR_PRINT);
}

int8_t				print_dirlist(t_dirlist *dir, t_opt *opt)
{
	if (opt->ldisp)
		return (print_dirlist_l(dir));
	else
	{
		if (dir->depth != 0)
			if (ft_printf("\n%s:\n", dir->name) == -1)
				return (DIR_ERR_PRINT);
		return (print_loop(dir, NULL));
	}
}

//int8_t				print_singleton(char *name); // TODO
