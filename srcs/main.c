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
	t_opt_u			opt;
	t_arg			*args;
	size_t			args_len;

	args = get_args(argc, argv, &opt, &args_len);
	if (!args)
	{
		display_dir(".", &(opt.opt_struct));
		return (0);
	}
	if (args_len > 1)
		opt.opt_struct.multi_arg = 1;
	if (parse_args(args, args_len, &(opt.opt_struct)))
		error_handler(NULL, 0);
	ft_memdel((void**)&(args));
	return (0);
}
