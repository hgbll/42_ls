#include <stdlib.h>
#include "libft.h"
#include "ft_ls.h"

void			exit_usage(void)
{
	ft_printf("usage: ls [-Ralrt] [file ...]\n");
	exit(EXIT_FAILURE);
}

void			add_option(const char c,
							t_options_u *options)
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
	options->opt_int[i] = 1;
}

int				get_options(t_options_u *options,
							int argc,
							char **argv)
{
	int			i;
	int			j;

	ft_bzero(options, sizeof(t_options_u));
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1])
	{
		j = 1;
		while (argv[i][j])
		{
			add_option(argv[i][j], options);
			j++;
		}
		i++;
	}
	return (i);
}
