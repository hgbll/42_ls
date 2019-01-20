/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:03:36 by hbally            #+#    #+#             */
/*   Updated: 2019/01/19 22:08:47 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t			get_stats(char *path, struct stat *stats,
								uint8_t nofollow)
{
	int8_t		status;

	if (nofollow)
		status = stat(path, stats);
	else
		status = stat(path, stats);
	return (status);
}
