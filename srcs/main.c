/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:06:39 by hbally            #+#    #+#             */
/*   Updated: 2019/01/17 17:47:45 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int8_t					arg_handler(char *arg, t_opt *opt)
{
	struct stat			stats;
	struct stat			sym_stats;

	if (lstat(arg, &stats) == -1)
		return (error_handler(arg, DIR_ERR_OPEN));
	else
	{
		if (get_type(stats.st_mode) == 'l')
		{
			sym_stats = stats;
			if (stat(arg, &stats) == -1)
				return (error_handler(arg, DIR_ERR_OPEN));
			if (get_type(stats.st_mode) == 'd' && !opt->ldisp)
				return (display_dir(arg, opt, 0));
			else
				return (ft_printf("TODO Disp symlink stats\n"));//
		}
		else if (get_type(stats.st_mode) == 'd')
			return (display_dir(arg, opt, 0));
		else
			return (ft_printf("TODO Disp file\n"));//
	}
}

int						main(int argc, char **argv)
{
	int					i;
	t_opt_u				opt;

	i = get_options(&opt, argc, argv);
	if (i == argc)
		display_dir(".", &(opt.opt_struct), 0);
	else
	{
		while (i < argc)
		{
			if (arg_handler(argv[i], &(opt.opt_struct)) < DIR_ERR_OPEN)
				exit(EXIT_FAILURE);
			i++;
		}
	}
	return (0);
}
