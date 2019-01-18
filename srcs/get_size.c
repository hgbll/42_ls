/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:58:51 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 21:01:04 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

/*
static uint16_t	digitlen(uint64_t n)
{
	uint16_t	len;
	
	len = 1;
	if (n != 0)
	{
		while ((n /= 10) > 0)
			len++;
	}
	return (len);
}
*/

int8_t			get_size(t_dirlist *dir, struct stat *stats, t_printdata *data)
{
	int8_t		status;

	status = 0;
	if (dir->is_dev && !is_anchor(data->name))
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
	{
		if (dir->is_dev && is_anchor(data->name))
		{
			data->paddings.size = data->paddings.major;
			data->paddings.size += data->paddings.major + 1;
		}
		status = ft_asprintf(&(data->size), "%*llu",
								data->paddings.size, stats->st_size);
	}
	return (status != -1 ? 0 : DIR_ERR_MALLOC);
}
