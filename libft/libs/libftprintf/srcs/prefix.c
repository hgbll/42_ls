/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 12:02:17 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 19:19:55 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include "libft.h"

/*
** Flag is represented as a bit code
** ...00001 > #
** ...00010 > 0
** ...00100 > -
** ...01000 > sp
** ...10000 > +
*/

static int		prefix_hashtag(t_index *params,
								const char *s,
								const char type,
								int print)
{
	if ((type == 'x' || type == 'o') && params->flags & 0x1)
	{
		write(1, "0x", (1 + (type == 'x')) * print);
		return (1 + (type == 'x'));
	}
	if (type == 'X' && (params->flags & 0x1) && s[0] != '0')
	{
		write(1, "0X", 2 * print);
		return (2);
	}
	return (0);
}

int				prefix(t_index *params,
						const char *s,
						const char type,
						int print)
{
	if (type == 'x' || type == 'X' || type == 'o')
		return (prefix_hashtag(params, s, type, print));
	if ((type != 'c' && type != 's' && type != 'u') &&
			(params->negative || params->flags & 0x18))
	{
		if (params->negative)
			write(1, "-", 1 * print);
		else if (params->flags & 0x10)
			write(1, "+", 1 * print);
		else if (params->flags & 0x8)
			write(1, " ", 1 * print);
		return (1);
	}
	return (0);
}
