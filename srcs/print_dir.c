/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:03:13 by hbally            #+#    #+#             */
/*   Updated: 2019/01/15 17:04:18 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void					tmp_printdir(t_dirlist *dir, char *name)
{
		size_t i = 0;

		if (dir->depth)
		{
			ft_putendl("");
			ft_putstr(name);
			ft_putendl(":");
		}
		while (i < dir->len)
		{
			ft_putendl(dir->data[i].name);
			i++;
		}
}
