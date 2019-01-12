/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:52:25 by hbally            #+#    #+#             */
/*   Updated: 2019/01/09 17:27:49 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void 				ft_inspect_file(char *name);

int					main(int arg_c, char **arg_v)
{
	if (arg_c != 2)
		return (1);

	ft_inspect_file(arg_v[1]);

	char *string = "%s and %s and %s\n";
	char *s1 = "hi";
	char *s2 = "hello";
	char *s3 = "welcome";

	int a = 1;
	int b = 1;
	int c = 0;

	ft_printf(string,
				a ? s1 : "",
				b ? s2 : "",
				c ? s3 : "");

	return (0);
}
