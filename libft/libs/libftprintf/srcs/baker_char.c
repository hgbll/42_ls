/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baker_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:19:18 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 19:11:03 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int				baker_char(char c, t_index *params)
{
	params->size = 1;
	return (printer_arg(&c, params->type, params));
}
