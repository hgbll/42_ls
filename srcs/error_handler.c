/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:04:59 by hbally            #+#    #+#             */
/*   Updated: 2019/01/19 21:58:23 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t				error_handler(char *arg, int8_t status)
{
	char			*str;

	if (arg)
	{
		str = ft_strrchr(arg, '/');
		if (str)
			ft_printf("ft_ls: %s: ", str + 1);
		else
			ft_printf("ft_ls: %s: ", arg);
	}
	else
		ft_printf("ft_ls: ");
	perror(NULL);
	return (status);
}
