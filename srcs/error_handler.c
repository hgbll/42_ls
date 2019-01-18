/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:04:59 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 14:00:22 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t				error_handler(char *arg, int8_t status)
{
	if (arg)
		ft_printf("ft_ls: %s: ", arg);
	else
		ft_printf("ft_ls: ");
	perror(NULL);
	return (status);
}
