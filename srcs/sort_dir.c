/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:35:37 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:27:21 by hbally           ###   ########.fr       */
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
	else if (t1.tv_nsec != t2.tv_nsec)
		result = t1.tv_nsec < t2.tv_nsec;
	else
		return (cmp_ascii(path1, path2, rev));
	return (rev ? !result : result);
}

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
	int8_t			cmp_ret;

	i = 0;
	while (i < dir->len - 1)
	{
		if ((cmp_ret = cmp(data[i].path, data[i + 1].path, rev)))
		{
			entry_swap(data, i);
			i = (i > 0) ? i - 1 : i;
		}
		else
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
	bubble_sort(dir, dir->data, cmp, opt->rev);
	return (0);
}
