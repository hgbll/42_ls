/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 11:53:04 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 12:00:56 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

size_t				find_point(const char *s)
{
	size_t			pos;

	pos = 0;
	while (s[pos] && s[pos] != '.')
		pos++;
	return (pos);
}

int					float_precision(const char *s, t_index *params)
{
	int				printed;
	size_t			point_pos;
	long long		to_add;

	printed = 0;
	point_pos = find_point(s);
	if (point_pos == params->size &&
			(params->precision != 0 ||
			(params->precision == 0 && params->flags & 0x1)))
	{
		ft_putchar('.');
		printed++;
	}
	if (params->precision == 0)
		return (printed);
	else if (params->precision != 0 && point_pos == params->size)
		return ((printed += printer_filler('0', params->precision)));
	else
	{
		to_add = params->precision - (params->size - (point_pos + 1));
		return (printer_filler('0', to_add > 0 ? to_add : 0));
	}
}

int					int_precision(t_index *params)
{
	if (params->precision != -1 &&
			params->precision > (long long)params->size)
		return (printer_filler('0', params->precision - params->size));
	return (0);
}
