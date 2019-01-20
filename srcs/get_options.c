/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:04:36 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:56:31 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ls.h"
#include "libft.h"

static void		exit_usage(void)
{
	ft_printf("usage: ls [-Ralrt] [file ...]\n");
	exit(EXIT_FAILURE);
}

static void		add_option(const char c, t_opt_u *opt)
{
	int			i;

	if (!ft_strchr("ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1", c))
	{
		ft_printf("ls: illegal option -- %c\n", c);
		exit_usage();
	}
	i = ft_strchri("Ralrt", c);
	if (i == -1)
	{
		ft_printf("ls: option not implemented -- %c\n", c);
		exit_usage();
	}
	opt->opt_int[i] = 1;
}

int				get_options(t_opt_u *opt, int argc, char **argv)
{
	int			i;
	int			j;

	ft_bzero(opt, sizeof(t_opt_u));
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1])
	{
		j = 1;
		while (argv[i][j])
		{
			add_option(argv[i][j], opt);
			j++;
		}
		i++;
	}
	return (i);
}
