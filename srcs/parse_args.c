/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:31 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 15:26:49 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static uint8_t			check_type(char c, int parse_option)
{
	if (parse_option == PARSE_FILES)
		return (c != 'd' && c != 0);
	if (parse_option == PARSE_DIRS)
		return (c == 'd');
	return (0);
}

static size_t			get_datalen(t_arg *args, int option, size_t len)
{
	size_t				i;
	size_t				datalen;

	i = 0;
	datalen = 0;
	while (i < len)
	{
		if (option == PARSE_FILES && args[i].type != 'd' && args[i].type != 0)
			datalen++;
		if (option == PARSE_DIRS && args[i].type == 'd')
			datalen++;
		i++;
	}
	return (datalen);
}

static int8_t			to_dir(t_dirlist *container, t_arg *args,
									size_t len, int parse_option)
{
	size_t				i;
	size_t				j;
	size_t				datalen;
	char				*name;

	if ((datalen = get_datalen(args, parse_option, len)) == 0)
		return (0);
	if (!(container->data = (t_entry*)ft_memalloc(sizeof(t_entry) * datalen)))
		return (error_handler(NULL, 0));
	container->len = datalen;
	i = 0;
	j = 0;
	while (i < len)
	{
		if (check_type(args[i].type, parse_option))
		{
			name = ft_strrchr(args[i].path, '/');
			container->data[j].path = args[i].path;
			container->data[j].name = !name ? args[i].path : name;
			container->data[j].is_subdir = 1;
			j++;
		}
		i++;
	}
	return (1);
}

int8_t					parse_args(t_arg *args, size_t len, t_opt *opt)
{
	t_dirlist			container;
	size_t				counter;

	counter = 0;
	container.is_container = 1;
	if ((to_dir(&container, args, len, PARSE_FILES)))
	{
		display_container(&container, opt);
		ft_memdel((void**)&(container.data));
		counter++;
	}
	if ((to_dir(&container, args, len, PARSE_DIRS)))
	{
		if (counter)
			ft_printf("\n");
		display_subdirs(&container, container.data, opt);
		ft_memdel((void**)&(container.data));
	}
	return (0);
}
