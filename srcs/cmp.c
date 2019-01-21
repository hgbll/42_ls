/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:05:46 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 19:25:34 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "libft.h"

int8_t				cmp_ascii(char *path1, char *path2)
{
	return (ft_strcmp(path1, path2) > 0);
}

int8_t				cmp_mtime(char *path1, char *path2)
{
	struct stat		stats;
	struct timespec	t1;
	struct timespec	t2;

	ft_bzero(&stats, sizeof(struct stat));
	get_stats(path1, &stats, NOFOLLOW);
	t1 = stats.st_mtimespec;
	get_stats(path2, &stats, NOFOLLOW);
	t2 = stats.st_mtimespec;
	if (t1.tv_sec != t2.tv_sec)
		return (t1.tv_sec < t2.tv_sec);
	if (t1.tv_nsec != t2.tv_nsec)
		return (t1.tv_nsec < t2.tv_nsec);
	return (cmp_ascii(path1, path2));
}
