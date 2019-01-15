/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:58:36 by hbally            #+#    #+#             */
/*   Updated: 2018/12/29 15:51:46 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

void		test_string(int (*f)(const char*, ...))
{
	char	*s = "loremipsumloremipsumloremipsumloremipsumloremipsumloremipsum";
	char	c = '0';

	f("%s\n", s);
	f("%s\n", NULL);

	f("%.2s\n", s);
	f("%.2s\n", NULL);

	f("%.0s\n", s);
	f("%.0s\n", NULL);

	f("%200s\n", s);
	f("%200s\n", NULL);

	f("%c\n", c);
	f("%c\n", 0);

	f("%.2c\n", c);
	f("%.2c\n", 0);

	f("%.0c\n", c);
	f("%.0c\n", 0);

	f("%200c\n", c);
	f("%200c\n", 0);
}
