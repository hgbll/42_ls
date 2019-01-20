/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:27 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:24:31 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static t_arg	*fill_args(char **argv, size_t *len, int start, t_opt *opt)
{
	size_t		i;
	t_arg		*args;

	if (!(args = (t_arg*)ft_memalloc(sizeof(t_arg) * (*len))))
	{
		error_handler(NULL, 0);
		return (NULL);
	}
	i = 0;
	while (i < *len)
	{
		args[i].path = argv[start + i];
		is_dir(&(args[i]), opt);
		i++;
	}
	return (args);
}

static void		sort_args(t_arg *args, size_t *len)
{
	size_t		i;
	size_t		j;
	size_t		unsorted;
	t_arg		swap;

	i = 0;
	unsorted = *len;
	while (i < *len)
	{
		j = 0;
		while (j < unsorted - 1)
		{
			if (ft_strcmp(args[j].path, args[j + 1].path) > 0)
			{
				swap = args[j + 1];
				args[j + 1] = args[j];
				args[j] = swap;
			}
			j++;
		}
		i++;
	}
}

static void		show_errors(t_arg *args, size_t *len)
{
	size_t		i;

	i = 0;
	while (i < *len)
	{
		if (args[i].type == 0)
		{
			errno = args[i].errno_value;
			error_handler(args[i].path, 0);
		}
		i++;
	}
}

t_arg			*get_args(int argc, char **argv, t_opt_u *opt, size_t *len)
{
	t_arg		*args;
	size_t		i;
	int			start;

	start = get_options(opt, argc, argv);
	if (start == argc)
		return (NULL);
	*len = 0;
	i = start;
	while (i++ < (size_t)argc)
		(*len)++;
	args = fill_args(argv, len, start, &(opt->opt_struct));
	if (args)
	{
		sort_args(args, len);
		show_errors(args, len);
	}
	return (args);
}
