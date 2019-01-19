/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:03:36 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 18:50:55 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t			get_stats(char *path, struct stat *stats,
								uint8_t nofollow)
{
	int8_t		status;

	if (nofollow)
		status = lstat(path, stats);
	else
		status = stat(path, stats);
	return (status);
}
