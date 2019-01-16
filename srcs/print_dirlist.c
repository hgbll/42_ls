/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:03:13 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 20:23:29 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t				print_loop(t_dirlist *dir,
								t_printdata *printdata,
								t_opt *opt)
{
	size_t			i;
	int8_t			status;

	i = 0;
	while (i < dir->len)
	{
		if (!opt->ldisp)
			status = print_entry(dir->data[i].name);
		else
			status = print_entry_l(dir->data[i].name, printdata);
		if (status)
			return (status);
		i++;
	}
	return (0);
}

static int8_t		print_dirlist_l(t_dirlist *dir, t_opt *opt)
{
	t_printdata		printdata;

	if (get_padding(dir, &printdata))
		return (STAT_RET_ERR);
	if (dir->depth != 0)
		if (ft_printf("\n%s:\n", dir->name) == -1)
			return (DIR_ERR_PRINT);
	if (ft_printf("total %llu\n", printdata.total_blocks))
			return (DIR_ERR_PRINT);
	return (print_loop(dir, &printdata, opt));
}

int8_t				print_dirlist(t_dirlist *dir, t_opt *opt)
{
	if (opt->ldisp)
		print_dirlist_l(dir, opt);
	else
	{
		if (dir->depth != 0)
			if (ft_printf("\n%s:\n", dir->name) == -1)
				return (DIR_ERR_PRINT);
	}
	return (print_loop(dir, NULL, opt));
}

//int8_t				print_singleton(char *name); // TODO
