#include <stdio.h>
#include "ls.h"
#include "libft.h"

int8_t				str_error_handler(char *string, char *arg, int8_t status)
{
	if (string)
	//	printf("ft_ls%s%s: %s\n", arg ? ": " : "", arg, string);

	/*tmp code*/
	ft_putstr("ft_ls");
	arg ? ft_putstr(": ") : ft_putstr("");
	ft_putstr(arg);
	ft_putstr(": ");
	ft_putendl(string);

	return (status);
}

int8_t				error_handler(char *arg, int8_t status)
{
//	printf("ft_ls%s%s: ", arg ? ": " : "", arg);

	/*tmp code*/
	ft_putstr("ft_ls");
	arg ? ft_putstr(": ") : ft_putstr("");
	ft_putstr(arg);
	ft_putstr(": ");
	perror(NULL);

	return (status);
}
