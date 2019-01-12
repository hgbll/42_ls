#ifndef FT_INSPECT_FILE_H
# define FT_INSPECT_FILE_H

typedef struct		s_flags
{
	uint16_t rights		: 9;
	uint16_t extra		: 3;
	uint16_t filetype	: 4;
}					t_flags;

typedef union		u_mode_flags
{
	mode_t		mode;
	t_flags		flags;
}					t_mode_flags;

typedef struct		s_printable_stats
{
	char			*name;
	char			type[17];
	char			rights[10];
	char			*last_modified;
}					t_printable_stats;

#endif
