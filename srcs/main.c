#include <sys/stat.h>
#include "libft.h"
#include "ls.h"

void					arg_handler(char *arg, t_opt *opt)
{
	struct stat			stats;
	struct stat			sym_stats;

	// USE READLINK ???
	if (lstat(arg, &stats) == -1)
		error_handler(arg, -1);
	else
	{
		if (is_symlink(stats.st_mode))
		{
			sym_stats = stats;
			stat(arg, &stats);
			if (is_dir(stats.st_mode) && !opt->ldisp)
				display_dir(arg, opt);
			else
				ft_printf("TODO Disp symlink stats\n");//
		}
		else if (is_dir(stats.st_mode))
			display_dir(arg, opt);
		else
			ft_printf("TODO Disp file\n");//
	}
}

int						main(int argc, char **argv)
{
	int					i;
	t_opt_u				opt;

	i = get_options(&opt, argc, argv);
	if (i == argc)
		display_dir(".", &(opt.opt_struct));
	else
	{
		while (i < argc)
		{
			arg_handler(argv[i], &(opt.opt_struct));
			i++;
		}
	}
	while(1);
	return (0);
}
