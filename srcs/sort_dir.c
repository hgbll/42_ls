/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:35:37 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 17:20:34 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void			entry_swap(t_entry *data, size_t index)
{
	t_entry			swap;

	swap = data[index];
	data[index] = data[index + 1];
	data[index + 1] = swap;
}

static void			bubble_sort(t_dirlist *dir, t_entry *data, cmp_ptr cmp,
									int8_t rev)
{
	size_t			i;
	size_t			j;
	size_t			unsorted;

	unsorted = dir->len;
	i = 0;
	while (i < dir->len)
	{
		j = 0;
		while (j < unsorted - 1)
		{
			if(cmp(data[j].path, data[j + 1].path, rev))
				entry_swap(data, j);
			j++;
		}
		i++;
	}
}

int8_t				sort_dir(t_dirlist *dir, t_opt *opt)
{
	cmp_ptr			cmp;
	
	if (opt->sort_mt)
		cmp = &cmp_mtime;
	else
		cmp = &cmp_ascii;
	if (dir->len > 0)
		bubble_sort(dir, dir->data, cmp, opt->rev);
	return (0);
}
