#ifndef LS_H
# define LS_H

# include <string.h>
# include <stdint.h>
# include <dirent.h>
# include <sys/stat.h>

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

typedef struct		s_dirlist
{
	DIR				*dirp;
	struct dirent	*data;
	size_t			len;
	blkcnt_t		total_blocks;
}					t_dirlist;

//TEST
/*
typedef struct		s_type
{
	uint16_t		type_int;
	char			type_char;
}					t_type;
*/

int					get_options(t_opt_u *opt,
								int argc,
								char **argv);
uint8_t				display_dir(char *arg, t_opt *opt);

uint8_t				error_handler(char *arg, uint8_t status);
uint8_t				str_error_handler(char *string, char *arg, uint8_t status);

uint8_t				is_symlink(uint16_t mode);
uint8_t				is_dir(uint16_t mode);
char				get_type(uint16_t mode);

#endif
