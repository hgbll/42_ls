/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:06:39 by hbally            #+#    #+#             */
/*   Updated: 2019/01/18 18:56:59 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int					main(int argc, char **argv)
{
	int				index;
	t_opt_u			opt;
	t_arg			*args;
	size_t			args_len;

	index = get_options(&opt, argc, argv);
	if (index == argc)
		display_dir(".", &(opt.opt_struct));
	else
	{
		args = get_args(argc, argv, index, &args_len);
		if (args_len > 1)
			opt.opt_struct.multi_arg = 1;
		if (!args || parse_args(args, args_len, &(opt.opt_struct)))
		{
			error_handler(NULL, 0);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
