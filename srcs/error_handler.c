#include <stdio.h>
#include "libft.h"

void				error_handler(char *arg)
{
	ft_printf("ft_ls: %s: ", arg);
	perror(NULL);
}
