#ifndef FT_LS_H
# define FT_LS_H

# include <stdint.h>

typedef struct		s_options
{
	uint8_t			recursive;
	uint8_t			hidden;
	uint8_t			verbose;
	uint8_t			reverse;
	uint8_t			sort_mtime;
}					t_options;

typedef union		u_options
{
	uint8_t			opt_int[5];
	t_options		opt_struct;
}					t_options_u;


int					get_options(t_options_u *options,
								int argc,
								char **argv);
#endif
