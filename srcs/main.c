#include <sys/stat.h>
#include "libft.h"
#include "ls.h"

uint8_t					get_type(uint16_t mode)
{
	mode &= 0xF000;
	if (mode == S_IFIFO)
		return (0);
	if (mode == S_IFCHR)
		return (1);
	if (mode == S_IFDIR)
		return (2);
	if (mode == S_IFBLK)
		return (3);
	if (mode == S_IFREG)
		return (4);
	if (mode == S_IFLNK)
		return (5);
	if (mode == S_IFSOCK)
		return (6);
	if (mode == S_IFWHT)
		return (7);
}

void					arg_handler(char *arg, t_opt *opt)
{
	struct stat			stats;
	struct stat			sym_stats;
	uint16_t			type;

	if (lstat(arg, &file_stats) != -1)
	{
		if (file_stats.st_mode & 0xF000 == S_IFLNK)
		{
			stat(arg, &file_stats);
			if (file_stats.st_mode & 0xF000 == S_IFDIR)
			ft_printf("Print symbolic link\n");//debug
		}
		else
			display_dir(arg, options);
	}
	else
		error_handler(arg);
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
	return (0);
}
