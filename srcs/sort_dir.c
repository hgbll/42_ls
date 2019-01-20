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

	i = 0;
	while (i < dir->len - 1)
	{
		if ((cmp(data[i].path, data[i + 1].path, rev)))
		{
			entry_swap(data, i);
			i = (i > 0) ? i - 1 : i;
		}
		else
			i++;
	}
}

/*
	algorithm quicksort(A, lo, hi) is
		if lo < hi then
			p := partition(A, lo, hi)
				quicksort(A, lo, p)
				quicksort(A, p + 1, hi)

	algorithm partition(A, lo, hi) is
		pivot := A[(lo + hi) / 2]
		i := lo - 1
		j := hi + 1
		loop forever
		do
				i := i + 1
			while A[i] < pivot

		do
				j := j - 1
			while A[j] > pivot

		if i >= j then
		return j

		swap A[i] with A[j]

static void			quicksort(t_entry *data,
								cmp_ptr cmp,
								int8_t rev)
{

}
*/
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
