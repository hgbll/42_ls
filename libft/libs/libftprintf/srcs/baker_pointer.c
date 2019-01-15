/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baker_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 14:56:23 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 15:01:44 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

/*
** Length is represented as a bit code
** ...00001 > hh
** ...00010 > h
** ...00100 > ll
** ...01000 > l
** ...10000 > L
*/

int				baker_pointer(void *p, t_index *params)
{
	params->type = 'x';
	if (!p)
	{
		ft_putstr("0x");
		return (baker_int(0, params) + 2);
	}
	params->flags |= 0x1;
	params->length |= 0x8;
	return (baker_long((unsigned long)p, params));
}
