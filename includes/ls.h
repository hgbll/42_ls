/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:11:23 by hbally            #+#    #+#             */
/*   Updated: 2019/01/20 17:57:38 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <stdint.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>

# define PARSE_FILES 1
# define PARSE_DIRS 2

# define IS_FILE 2
# define IS_DIR 1
# define IS_ERR 0

# define FOLLOW 0
# define NOFOLLOW 1

# define DIR_ERR_OPEN -1
# define DIR_ERR_CLOSE -2
# define DIR_ERR_MALLOC -3
# define DIR_ERR_PRINT -3

# define ERR_PRINT 1
# define ERR_NOPRINT 0

/*
**	Options Storage
*/

typedef struct		s_opt
{
	uint8_t			deep;
	uint8_t			nohide;
	uint8_t			ldisp;
	uint8_t			rev;
	uint8_t			sort_mt;
	uint8_t			multi_arg;
}					t_opt;

typedef union		u_opt
{
	uint8_t			opt_int[6];
	t_opt			opt_struct;
}					t_opt_u;

/*
**	Directory description
*/

typedef struct		s_entry
{
	char			*path;
	char			*name;
	uint8_t			is_subdir;
}					t_entry;

typedef struct		s_dirlist
{
	char			*name;
	size_t			namlen;
	uint8_t			is_container;
	uint8_t			is_dev;
	DIR				*dirp;
	t_entry			*data;
	size_t			len;
}					t_dirlist;

/*
**	Mode Storage
*/

typedef struct		s_bits
{
	uint16_t		rights		: 9;
	uint16_t		extra		: 3;
	uint16_t		filetype	: 4;
}					t_bits;

typedef union		u_mode
{
	mode_t			raw;
	t_bits			bits;
}					t_mode;

/*
**	Print Data
*/

typedef struct		s_paddings
{
	uint16_t		links;
	uint16_t		size;
	uint16_t		ownername;
	uint16_t		groupname;
	uint16_t		major;
	uint16_t		minor;
}					t_paddings;

typedef struct		s_printdata
{
	t_paddings		paddings;
	blkcnt_t		total_blocks;
	char			*name;
	char			type;
	char			mode[12];
	char			time[13];
	char			*path;
	char			*size;
	char			*target;
	char			*ownername;
	int				no_ownername;
	char			*groupname;
	int				no_groupname;
}					t_printdata;

/*
**	Args Parsing
*/

typedef struct		s_arg
{
	char			*path;
	char			type;
	int				errno_value;
}					t_arg;

/*
**	Main Functions
*/

int					get_options(t_opt_u *opt, int argc, char **argv);
t_arg				*get_args(int argc, char **argv, t_opt_u *opt, size_t *len);
int8_t				parse_args(t_arg *args, size_t len, t_opt *opt);
void				display_container(t_dirlist *container, t_opt *opt);
int8_t				display_dir(char *name, t_opt *opt);
int8_t				display_subdirs(t_dirlist *dir, t_entry *data, t_opt *opt);
int8_t				get_dirlist(t_dirlist *dir, t_opt *opt);
int8_t				sort_dir(t_dirlist *dir, t_opt *opt);
int8_t				print_dirlist(t_dirlist *dir, t_opt *opt);
int8_t				print_entry(t_dirlist *dir, char *name, t_printdata *data);
int8_t				exit_dir(t_dirlist *dir, char *name, int8_t status,
								int8_t origin);

/*
** Helper Functions
*/

char				*path(t_dirlist *dir, char *to_add);
int8_t				error_handler(char *arg, int8_t status);
uint8_t				is_anchor(char *name);
uint8_t				is_hidden(char *name, t_opt *opt);
void				is_dir(t_arg *arg, t_opt *opt);
int8_t				is_dir_deep(t_entry *entry);
int8_t				get_printdata(t_dirlist *dir, struct stat *stats,
									t_printdata *data);
int8_t				free_printdata(t_printdata *data, int8_t status);
int8_t				get_padding(t_dirlist *dir, t_printdata *data);
int8_t				get_names(struct stat *stats, t_printdata *data);
int8_t				get_mode(struct stat *stats, t_printdata *data);
int8_t				get_time(struct stat *stats, t_printdata *data);
int8_t				get_size(t_dirlist *dir, struct stat *stats,
								t_printdata *data);
char				get_type(uint16_t mode);
int8_t				get_stats(char *path, struct stat *stats,
								uint8_t nofollow);
int8_t				get_symlink(t_printdata *data);
char				*mkpath(t_dirlist *dir, char *to_add);
int8_t				cmp_mtime(char *path1, char *path2);
int8_t				cmp_ascii(char *path1, char *path2);
typedef int8_t		(*cmp_ptr)(char*, char*);

#endif
