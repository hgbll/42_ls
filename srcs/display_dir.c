#include <dirent.h>
#include <stdio.h>
#include "libft.h"
#include "ls.h"

uint8_t				exit_dir(t_dirlist *dir, char *name, uint8_t status)
{
	if (dir->data)
		ft_memdel((void*)&(dir->data));
	else
		str_error_handler("Malloc Failure", name, -1);
	if (closedir(dir->dirp) == -1)
	{
		status = -1;
		str_error_handler(NULL, name, -1);
	}
	return (status);
}

uint8_t				display_subdirs(t_dirlist *dir,
									struct dirent *data,
									t_opt *opt)
{
	size_t			i;

	i = 0;
	while (i < dir->len)
	{
		if (is_dir(data[i]))
			//TODO
	}
}

uint8_t				display_dir(char *arg, t_opt *opt)
{
	t_dirlist		dir;
	uint8_t			status;
	
	ft_bzero(&dir, sizeof(dir));
	dir.dirp = opendir(arg);
	if (!dir.dirp)
		return (error_handler(arg, 0));
//	dir.data = get_dir(dir.dirp, opt)
	if (dir.data)
	{
//		sort_dir(&dir, opt);
//		print_dir(&dir, opt);
//		status = display_subdirs(&dir, dir.data, opt);
	}
	return (exit_dir(&dir, arg, status));
}
