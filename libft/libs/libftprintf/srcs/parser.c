/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:15:51 by hbally            #+#    #+#             */
/*   Updated: 2018/12/22 17:05:44 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft.h"

size_t				parser(const char *format,
							size_t *head,
							va_list *args)
{
	t_index			params;
	int				printed;

	(*head)++;
	ft_bzero(&params, sizeof(t_index));
	params.precision = -1;
	printed = -1;
	while (format[*head])
	{
		if (!check_flag(format[*head], &params))
			if (!check_width(format, head, &params))
				if (!check_precision(format, head, &params))
					if (!check_length(format, head, &params))
						printed = dispatcher(format[*head], args, &params);
		if (printed != -1)
			return ((size_t)printed);
		(*head)++;
	}
	(*head)--;
	return (0);
}
