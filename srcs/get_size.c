/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:58:51 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:50:14 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "libft.h"

static int8_t	get_numbers(struct stat *stats, t_printdata *data)
{
	int8_t		status;

	if (data->type == 'c' || data->type == 'b')
		status = ft_asprintf(&(data->size), "%*d, %*d",
					data->pad.major,
					(stats->st_rdev & 0xFF000000) >> 24,
					data->pad.minor, stats->st_rdev & 0x00FFFFFF);
	else
		status = ft_asprintf(&(data->size), "%*d",
					data->pad.major + data->pad.minor + 2,
					stats->st_rdev);
	return (status);
}

int8_t			get_size(t_dirlist *dir, struct stat *stats, t_printdata *data)
{
	int8_t		status;

	status = 0;
	if (dir->is_dev && (data->type == 'c' || data->type == 'b'))
		status = get_numbers(stats, data);
	else
	{
		if (dir->is_dev)
		{
			data->pad.size = data->pad.major +
									data->pad.minor + 2;
		}
		status = ft_asprintf(&(data->size), "%*llu",
								data->pad.size, stats->st_size);
	}
	return (status != -1 ? 0 : DIR_ERR_MALLOC);
}
