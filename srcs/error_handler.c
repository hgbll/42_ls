#include <stdio.h>
#include "ls.h"
#include "libft.h"

uint8_t				str_error_handler(char *string, char *arg, uint8_t status)
{
	if (string)
		ft_printf("ft_ls%s%s: %s\n", arg ? ": " : "", arg, string);
	return (status);
}

uint8_t				error_handler(char *arg, uint8_t status)
{
	ft_printf("ft_ls%s%s: ", arg ? ": " : "", arg);
	perror(NULL);
	return (status);
}
