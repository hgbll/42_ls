/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:44:30 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 11:41:07 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft.h"

/*
** printf loop layout (from start to end) :
**
** ft_printf	| advances head until a '%' or '\0' is found
** printer_fmt	| trivial print of format string from format[0] or form last '%'
**					then call parser if head is a '%'
** parser 		| if '%' was found, parse all parameters and store in a struct
**					then call dispatcher if a type identifier was found
** dispatcher	| calls the correct baker using parser output
** baker  		| conversion form raw input to string
** printer_arg	| prints the resulting output from baking pipe
**					(applies prefix/width/precision)
**					then returns chars printed back to ft_printf
*/

int				ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		head;
	size_t		printed;

	printed = 0;
	if (format && *format)
	{
		va_start(args, format);
		head = 0;
		while (format[head])
		{
			if (format[head] == '%')
				printed += printer_fmt(format, &head, &args);
			head++;
		}
		printed += printer_fmt(format, &head, &args);
		va_end(args);
	}
	return (printed);
}
