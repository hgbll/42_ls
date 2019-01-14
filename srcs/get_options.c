#include <stdlib.h>
#include "libft.h"
#include "ls.h"

void			exit_usage(void)
{
	printf("usage: ls [-Ralrt] [file ...]\n");
	exit(EXIT_FAILURE);
}

void			add_option(const char c,
							t_opt_u *opt)
{
	int			i;

	if (!ft_strchr("ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1", c))
	{
		printf("ls: illegal option -- %c\n", c);
		exit_usage();
	}
	i = ft_strchri("Ralrt", c);
	if (i == -1)
	{
		printf("ls: option not implemented -- %c\n", c);
		exit_usage();
	}
	opt->opt_int[i] = 1;
}

int				get_options(t_opt_u *opt,
							int argc,
							char **argv)
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
