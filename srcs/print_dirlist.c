/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:03:13 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 20:48:26 by hbally           ###   ########.fr       */
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
		if (printdata)
		{
			printdata->path = dir->data[i].path;
			printdata->name = dir->data[i].name;
		}
		if((status = print_entry(dir, dir->data[i].name, printdata)))
			return (status);
		i++;
	}
	return (0);
}

static int8_t		print_dirlist_l(t_dirlist *dir)
{
	t_printdata		printdata;

	ft_printf("Entering print\n");//
	ft_bzero(&printdata, sizeof(t_printdata));
	if (get_padding(dir, &printdata))
		return (DIR_ERR_OPEN);
	if (dir->depth != 0)
	   	if (ft_printf("\n%s:\n", dir->name) == -1)
			return (DIR_ERR_PRINT);
	if (ft_printf("total %llu\n", printdata.total_blocks) == -1)
		return (DIR_ERR_PRINT);
	ft_printf("Starting print loop\n");//
	return (print_loop(dir, &printdata));
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
