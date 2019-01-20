/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:04:59 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 13:52:20 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t				error_handler(char *arg, int8_t status)
{
	char			*path;
	char			*string;

	string = NULL;
	if (arg)
	{
		path = ft_strrchr(arg, '/');
		if (path)
			ft_asprintf(&string, "ft_ls: %s", path + 1);
		else
			ft_asprintf(&string, "ft_ls: %s", arg);
	}
	else
		ft_asprintf(&string, "ft_ls: ");
	perror(string);
	if (string)
		ft_memdel((void**)&(string));
	return (status);
}
