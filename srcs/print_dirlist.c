/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:03:13 by hbally            #+#    #+#             */
/*   Updated: 2019/01/15 19:48:21 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t					print_dirlist(t_dirlist *dir, t_entry *data, t_opt *opt)
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
	return (0);
}

