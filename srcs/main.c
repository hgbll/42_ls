#include "libft.h"
#include "ft_ls.h"

int						main(int argc, char **argv)
{
	int					i;
	t_options_u			options;

	i = get_options(&options, argc, argv);
	if (i == argc)
		display_dir(".", &(options.opt_struct));
//		ft_printf(".\n");
	else
	{
		while (i < argc)
		{
			display_dir(argv[i], &(options.opt_struct));
			ft_printf("%s\n", argv[i]);
			i++;
		}
	}
//	ft_printf("%d\n", options.opt_int[0]);
//	ft_printf("%d\n", options.opt_int[1]);
//	ft_printf("%d\n", options.opt_int[2]);
//	ft_printf("%d\n", options.opt_int[3]);
//	ft_printf("%d\n", options.opt_int[4]);
	return (0);
}
