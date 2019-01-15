/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:11:23 by hbally            #+#    #+#             */
/*   Updated: 2019/01/15 17:14:28 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include "libft.h"

# define FILE_ERR_OPEN -1
# define DIR_ERR_OPEN -1
# define DIR_ERR_CLOSE -2
# define DIR_ERR_MALLOC -3
# define CUR_DIR_ERR 1
# define SUB_DIR_ERR 0

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

typedef struct		s_entry
{
	char			*name;
	uint8_t			subdir;
}					t_entry;

typedef struct		s_dirlist
{
	char			*name;
	size_t			namlen;
	size_t			depth;
	DIR				*dirp;
	t_entry			*data;
	size_t			len;
	blkcnt_t		total_blocks;
}					t_dirlist;

int					get_options(t_opt_u *opt, int argc, char **argv);
int8_t				display_dir(char *name,
								uint32_t namlen,
								t_opt *opt,
								size_t depth);
int8_t				exit_dir(t_dirlist *dir,
								char *name,
								int8_t status,
								int8_t origin);
int8_t				error_handler(char *arg, int8_t status);
int8_t				str_error_handler(char *string, char *arg, int8_t status);
int8_t				get_dirlist(t_dirlist *dir);

uint8_t				is_symlink(uint16_t mode);
uint8_t				is_dir(uint16_t mode);
char				get_type(uint16_t mode);

void				tmp_printdir(t_dirlist *dir, char *name);// DEBUG

#endif
