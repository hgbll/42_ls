/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:30:12 by hbally            #+#    #+#             */
/*   Updated: 2019/01/16 15:37:26 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_PRINT_H
# define LS_PRINT_H

/*
**	Mode Storage
*/

typedef struct		s_bits
{
	uint16_t 		rights		: 9;
	uint16_t 		extra		: 3;
	uint16_t 		filetype	: 4;
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
	uint8_t			links;
	uint8_t			size;
	uint8_t			ownername;
	uint8_t			groupname;

}					t_paddings;

typedef struct		s_printdata
{
	blkcnt_t		total_blocks;
	t_paddings		paddings;
	char			rights_symbols[3];
	char			mode[12];
	char			time[13];
	char			*ownername;
	char			*groupname;
	char			*linkpath;
}					t_printdata;

#endif
