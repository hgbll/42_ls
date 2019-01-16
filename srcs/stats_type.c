/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:05:45 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 15:25:12 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

uint8_t					is_symlink(uint16_t mode)
{
	if ((mode & 0xF000) == S_IFLNK)
		return (1);
	else
		return (0);
}

uint8_t					is_dir(uint16_t mode)
{
	if ((mode & 0xF000) == S_IFDIR)
		return (1);
	else
		return (0);
}
