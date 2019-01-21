/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:35:37 by hbally            #+#    #+#             */
/*   Updated: 2019/01/21 12:05:54 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void			entry_swap(t_entry *data, int i1, int i2)
{
	t_entry			swap;

	swap = data[i1];
	data[i1] = data[i2];
	data[i2] = swap;
}

static void			reverse(t_entry *data, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			mid;

	i = 0;
	j = len - 1;
	mid = len / 2;
	while (i < mid)
	{
		entry_swap(data, i, j);
		i++;
		j--;
	}
}

static int			partition(t_entry *data, int lo, int hi,
								int8_t (*cmp)(char*, char*))
{
	t_entry			pivot;
	int				i;
	int				j;

	pivot = data[(lo + hi) / 2];
	i = lo - 1;
	j = hi + 1;
	while (1)
	{
		i++;
		while (cmp(pivot.path, data[i].path))
			i++;
		j--;
		while (cmp(data[j].path, pivot.path))
			j--;
		if (i >= j)
			return (j);
		entry_swap(data, i, j);
	}
}

static void			quicksort(t_entry *data, int lo, int hi,
								int8_t (*cmp)(char*, char*))
{
	int				p;

	if (lo < hi)
	{
		p = partition(data, lo, hi, cmp);
		quicksort(data, lo, p, cmp);
		quicksort(data, p + 1, hi, cmp);
	}
}

int8_t				sort_dir(t_dirlist *dir, t_opt *opt)
{
	int8_t			(*cmp)(char*, char*);

	if (opt->sort_mt)
		cmp = &cmp_mtime;
	else
		cmp = &cmp_ascii;
	if (dir->len > 0)
	{
		quicksort(dir->data, 0, (int)(dir->len - 1), cmp);
		if (opt->rev)
			reverse(dir->data, dir->len);
	}
	return (0);
}
