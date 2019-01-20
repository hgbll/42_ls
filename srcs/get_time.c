/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:01:45 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:49:45 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ls.h"
#include "libft.h"

int8_t			get_time(struct stat *stats, t_printdata *data)
{
	char		*time_raw;
	time_t		mtime;
	time_t		now;

	mtime = stats->st_mtimespec.tv_sec;
	if ((time_raw = ctime(&(mtime))))
	{
		now = time(NULL);
		ft_strncpy(data->time, &time_raw[4], 7);
		if (now != -1 && ft_abstime(now - mtime) > 15770000)
			ft_strncpy(&data->time[7], &time_raw[19], 5);
		else
			ft_strncpy(&data->time[7], &time_raw[11], 5);
		data->time[12] = '\0';
	}
	return (0);
}
