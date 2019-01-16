/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:01:45 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 18:17:00 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t		get_time(struct stat *stats, t_printdata *data)
{
	/*TEMPORARY*/
	char		*str;

	str = ctime(&(stats->st_mtimespec.tv_sec)); // check return
	str = ft_strsub(str, 4, 12); //dont use a malloc here
	ft_strcpy(data->time, str);
	free(str);
	return (0);
}
