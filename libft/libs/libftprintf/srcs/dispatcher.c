/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 11:38:52 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 11:39:11 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

/*
** Length is represented as a bit code
** ...00001 > hh (1)
** ...00010 > h (2)
** ...00100 > ll (4)
** ...01000 > l (8)
** ...10000 > L (10)
*/

int				dispatcher(char c, va_list *args, t_index *params)
{
	params->type = (c != '%') ? c : 'c';
	if (c == '%')
		return (baker_char('%', params));
	if (c == 'c')
		return (baker_char(va_arg(*args, int), params));
	if (c == 's')
		return (baker_string(va_arg(*args, char*), params));
	if (c == 'p')
		return (baker_pointer(va_arg(*args, void*), params));
	if (c == 'd' || c == 'i' || c == 'o' || c == 'x' || c == 'X' || c == 'u')
	{
		if (params->length & 0x4)
			return (baker_longlong(va_arg(*args, long long), params));
		if (params->length & 0x8)
			return (baker_long(va_arg(*args, long), params));
		return (baker_int(va_arg(*args, int), params));
	}
	if (c == 'f')
	{
		if (params->length & 0x10)
			return (baker_longdouble(va_arg(*args, long double), params));
		return (baker_double(va_arg(*args, double), params));
	}
	params->type = 0;
	return (-1);
}
