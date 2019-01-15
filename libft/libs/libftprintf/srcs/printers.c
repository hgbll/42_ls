/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:13:36 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 17:50:52 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

/*
**	--- printer_arg() ---
**
**	Prints arguments to printf with the correct format
**
**	Pipe order :
**
**	Right align (default) :
**	(width or prefix(1)) > (int_precision) > value > (float_precision)
**
**	Left align :
**	(prefix(1)) > (int_precision) > value > (float_precision) > (width)
**
**	(1) : prefix applies one of ('-', '+', ' ', '0/0x/0X')
**
** Flag is represented as a bit code
** ...00001 > #
** ...00010 > 0
** ...00100 > -
** ...01000 > sp
** ...10000 > +
*/

static int			arg_prefixes(const char *s, const char c, t_index *params)
{
	int				printed;

	printed = 0;
	special_handler(s, c, params);
	if (!(params->flags & 0x4) && (!(params->flags & 0x2) ||
			(c != 'f' && params->precision != -1)))
	{
		printed += width(s, c, params, 1);
		printed += prefix(params, s, c, 1);
	}
	else
	{
		printed += prefix(params, s, c, 1);
		if (!(params->flags & 0x4))
			printed += width(s, c, params, 1);
	}
	return (printed);
}

int					printer_arg(const char *s, const char c, t_index *params)
{
	int				printed;

	printed = arg_prefixes(s, c, params);
	printed += (c != 's' && c != 'c' && c != 'f') ? int_precision(params) : 0;
	if ((write(1, s, params->size) == -1))
		return (printed);
	printed += params->size;
	printed += (c == 'f') ? float_precision(s, params) : 0;
	printed += (params->flags & 0x4) ? width(s, c, params, 1) : 0;
	return (printed);
}

/*
**	--- printer_filler() ---
**	Prints filler chars ' ' or '0' when needed by width
**	or precision.
*/

int					printer_filler(const char c, long long len)
{
	char			*buffer;
	int				i;

	if (len <= 999999)
	{
		buffer = ft_strnew(len);
		if (buffer)
		{
			i = 0;
			while (i < len)
			{
				buffer[i] = c;
				i++;
			}
			write(1, buffer, len);
			free(buffer);
			return ((int)len);
		}
	}
	return (0);
}

/*
**	--- printer_fmt() ---
**	Prints format in between arguments.
*/

size_t				printer_fmt(const char *format,
								size_t *head,
								va_list *args)
{
	static size_t	head_old;
	size_t			printed;

	printed = *head - head_old;
	write(1, &(format[head_old]), *head - head_old);
	if (format[*head])
	{
		printed += parser(format, head, args);
		head_old = *head + 1;
	}
	else
		head_old = 0;
	return (printed);
}
