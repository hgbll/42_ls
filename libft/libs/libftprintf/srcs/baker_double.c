/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baker_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:20:54 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 17:21:21 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

static int		check_special(double n, t_index *params)
{
	char				string[10];
	int					printed;
	unsigned long long	*ptr;

	string[0] = '\0';
	ptr = (unsigned long long*)(&n);
	if (*ptr == 0x7FF0000000000000ULL)
		ft_strcpy(string, "inf");
	else if (*ptr == 0xFFF0000000000000ULL)
		ft_strcpy(string, "-inf");
	else if (*ptr == 0x7FF8000000000000ULL)
		ft_strcpy(string, "nan");
	else if (*ptr == 0x8000000000000000ULL)
		params->negative = 1;
	if (string[0] != '\0')
	{
		params->type = 's';
		params->precision = -1;
		if (params->flags & 0x2)
			params->flags -= 0x2;
		printed = baker_string(string, params);
		return (printed);
	}
	return (0);
}

int				baker_double(double n, t_index *params)
{
	char		*result;
	int			printed;

	printed = 0;
	printed = check_special(n, params);
	if (printed != 0)
		return (printed);
	if (n < .0f)
		params->negative = 1;
	if (params->precision == -1)
		params->precision = 6;
	if ((result = ft_dtoa(n)))
		if ((result = ft_round_double(result, params->precision)))
		{
			params->size = ft_strlen(result);
			printed = printer_arg(result, params->type, params);
			free(result);
			return (printed);
		}
	return (0);
}
