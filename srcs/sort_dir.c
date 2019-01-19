/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:35:37 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 17:54:33 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int8_t		cmp_ascii(char *name1, char *name2, int8_t rev)
{
	int8_t			result;

	result = ft_strcmp(name1, name2) > 0;
	return (rev ? !result : result);
}

static int8_t		cmp_mtime(char *path1, char *path2, int8_t rev)
{
	struct stat		stats;
	int8_t			result;
	struct timespec	t1;
	struct timespec	t2;

	ft_bzero(&stats, sizeof(struct stat));
	get_stats(path1, &stats, NOFOLLOW);
	t1 = stats.st_mtimespec;
	get_stats(path2, &stats, NOFOLLOW);
	t2 = stats.st_mtimespec;
	if (t1.tv_sec != t2.tv_sec)
		result = t1.tv_sec < t2.tv_sec;
	else
		result = t1.tv_nsec < t2.tv_nsec;
	return (rev ? !result : result);
}

static void			entry_swap(t_entry *data, size_t index)
{
	t_entry			swap;

	swap = data[index];
	data[index] = data[index + 1];
	data[index + 1] = swap;
}

static int8_t		bubble_sort(t_dirlist *dir,
									t_entry *data,
									cmp_ptr cmp,
									int8_t rev)
{
	size_t			i;
	size_t			j;
	size_t			unsorted;
	int8_t			cmp_ret;

	unsorted = dir->len;
	i = 0;
	while (i < dir->len)
	{
		j = 0;
		while (j < unsorted - 1)
		{
			cmp_ret = cmp(data[j].path, data[j + 1].path, rev);
			if (cmp_ret == -1)
				return (DIR_ERR_OPEN);
			if (cmp_ret)
				entry_swap(data, j);
			j++;
		}
		i++;
	}
	return (0);
}

int8_t					sort_dir(t_dirlist *dir, t_opt *opt)
{
	cmp_ptr			cmp;

	if (opt->sort_mt)
		cmp = &cmp_mtime;
	else
		cmp = &cmp_ascii;
	return (bubble_sort(dir, dir->data, cmp, opt->rev));
}
