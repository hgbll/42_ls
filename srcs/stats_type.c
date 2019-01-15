/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:05:45 by hbally            #+#    #+#             */
/*   Updated: 2019/01/15 17:05:51 by hbally           ###   ########.fr       */
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

char					get_type(uint16_t mode)
{
	mode &= 0xF000;
	if (mode == S_IFREG)
		return ('-');
	else if (mode == S_IFDIR)
		return ('d');
	else if (mode == S_IFLNK)
		return ('l');
	else if (mode == S_IFIFO)
		return ('p');
	else if (mode == S_IFSOCK)
		return ('s');
	else if (mode == S_IFCHR)
		return ('c');
	else if (mode == S_IFBLK)
		return ('b');
	else if (mode == S_IFWHT)
		return ('w');
	else
		return ('-');
}
