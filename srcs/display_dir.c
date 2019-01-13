#include <dirent.h>
#include <stdio.h>
#include "libft.h"
#include "ls.h"

void				display_dir(char *arg, t_opt *opt)
{
	DIR				*dir;

	dir = opendir(arg);
	if (dir)
	{
		
	}
	else
		error_handler(arg);
}
