/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baker_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:20:54 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 17:14:14 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

int				baker_longdouble(long double n, t_index *params)
{
	char		*result;
	int			printed;

	if (n < .0f)
		params->negative = 1;
	if (params->precision == -1)
		params->precision = 6;
	if ((result = ft_ldtoa(n)))
		if ((result = ft_round_double(result, params->precision)))
		{
			params->size = ft_strlen(result);
			printed = printer_arg(result, params->type, params);
			free(result);
			return (printed);
		}
	return (0);
}
