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

int8_t				cmp_ascii(char *name1, char *name2, int8_t rev)
{
	int8_t			result;

	result = ft_strcmp(name1, name2) > 0;
	return (rev ? !result : result);
}

int8_t				cmp_mtime(char *path1, char *path2, int8_t rev)
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
	{
		ft_printf("Seconds diff\n");
		result = t1.tv_sec < t2.tv_sec;
		return (rev ? !result : result);
	}
	if (t1.tv_nsec != t2.tv_nsec)
	{
		ft_printf("NanoSeconds diff\n");
		result = t1.tv_nsec < t2.tv_nsec;
		return (rev ? !result : result);
	}
	ft_printf("Ascii\n");
	ft_printf("_______\n");
	return (cmp_ascii(path1, path2, 0));
}
