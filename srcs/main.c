#include <sys/stat.h>
#include <stdlib.h>
#include "libft.h"
#include "ls.h"

int8_t					arg_handler(char *arg, t_opt *opt)
{
	struct stat			stats;
	struct stat			sym_stats;

	// USE READLINK ???
	if (lstat(arg, &stats) == -1)
		return (error_handler(arg, -1));
	else
	{
		if (is_symlink(stats.st_mode))
		{
			sym_stats = stats;
			stat(arg, &stats);
			if (is_dir(stats.st_mode) && !opt->ldisp)
				return (display_dir(arg, (uint32_t)ft_strlen(arg), opt, 0));
			else
				return (printf("TODO Disp symlink stats\n"));//
		}
		else if (is_dir(stats.st_mode))
			return (display_dir(arg, (uint32_t)ft_strlen(arg), opt, 0));
		else
			return (printf("TODO Disp file\n"));//
	}
}

int						main(int argc, char **argv)
{
	int					i;
	t_opt_u				opt;

	i = get_options(&opt, argc, argv);
	if (i == argc)
		display_dir(".", (uint32_t)1, &(opt.opt_struct), 0);
	else
	{
		while (i < argc)
		{
			if (arg_handler(argv[i], &(opt.opt_struct)) == -2)
				exit(EXIT_FAILURE);
			i++;
		}
	}
	return (0);
}
