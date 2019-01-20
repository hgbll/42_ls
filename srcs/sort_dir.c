/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:35:37 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 19:25:48 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

#include "libft.h" //DEBUG
#include "stdlib.h" //DEBUG

static void			entry_swap(t_entry *data, int i1, int i2)
{
	t_entry			swap;

	swap = data[i1];
	data[i1] = data[i2];
	data[i2] = swap;
}

static int			partition(t_entry *data,
								t_pos pos,
								cmp_ptr cmp,
								int8_t rev)
{
	t_entry			pivot;
	int				i;
	int				j;

	pivot = data[(pos.lo + pos.hi) / 2];
	i = pos.lo - 1;
	j = pos.hi + 1;
	while (1)
	{
		i++;
		while (cmp(pivot.path, data[i].path, rev))
			i++;
		j--;
		while (cmp(data[j].path, pivot.path, rev))
			j--;
//		if (pos.lo == 1 && pos.hi == 2)
//			ft_printf("i = %d, j = %d\n", i, j);
		if (i >= j)
			return (j);
		entry_swap(data, i, j);
	}
}

static void			quicksort(t_entry *data,
								t_pos pos,
								cmp_ptr cmp,
								int8_t rev)
{
	t_pos			new;
	int				p;
	
	if (pos.lo < pos.hi)
	{
		p = partition(data, pos, cmp, rev);
		new.lo = pos.lo;
		new.hi = p;
//		ft_printf("[1]Quicksorting from %d to %d\n", new.lo, new.hi);
		quicksort(data, new, cmp, rev);
		new.lo = p + 1;
		new.hi = pos.hi;
//		ft_printf("[2]Quicksorting from %d to %d\n", new.lo, new.hi);
		quicksort(data, new, cmp, rev);
	}
}

int8_t				sort_dir(t_dirlist *dir, t_opt *opt)
{
	cmp_ptr			cmp;
	t_pos			pos;
	
	if (opt->sort_mt)
		cmp = &cmp_mtime;
	else
		cmp = &cmp_ascii;
	if (dir->len > 0)
	{
		pos.lo = 0;
		pos.hi = dir->len - 1;
		pos.max = pos.hi;
		quicksort(dir->data, pos, cmp, opt->rev);
	}
	exit(0);
	return (0);
}
