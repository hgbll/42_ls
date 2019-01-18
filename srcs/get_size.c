/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:58:51 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 16:10:25 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t			get_size(t_dirlist *dir, struct stat *stats, t_printdata *data)
{
	int8_t		status;

	status = 0;
	if (dir->is_dev)
	{
		if (data->type == 'c' || data->type == 'b')
			status = ft_asprintf(&(data->size), "%*d, %*d",
						data->paddings.major,
						(stats->st_rdev & 0xFF000000) >> 24,
						data->paddings.minor, stats->st_rdev & 0x00FFFFFF);
		else
			status = ft_asprintf(&(data->size), "%*d",
						data->paddings.major + data->paddings.minor + 2, 0);
	}
	else
		status = ft_asprintf(&(data->size), "%*llu",
								data->paddings.size, stats->st_size);
	return (status != -1 ? 0 : DIR_ERR_MALLOC);
}
