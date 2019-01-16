/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:04:51 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 18:39:03 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t			get_symlink(char *name, struct stat *stats, t_printdata *data)
{
	if (stats && data && name)
		return (0);
	return (0);
}
