#ifndef LS_H
# define LS_H

# include <stdint.h>

typedef struct		s_opt
{
	uint8_t			deep;
	uint8_t			nohide;
	uint8_t			ldisp;
	uint8_t			rev;
	uint8_t			sort_mt;
}					t_opt;

typedef union		u_opt
{
	uint8_t			opt_int[5];
	t_opt			opt_struct;
}					t_opt_u;


int					get_options(t_opt_u *opt,
								int argc,
								char **argv);
void				display_dir(char *arg, t_opt *opt);
void				error_handler(char *arg);

#endif
