/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:12:38 by hbally            #+#    #+#             */
/*   Updated: 2019/01/09 17:55:42 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <string.h>

typedef struct		s_index
{
	char			type;
	int				length;
	long long		precision;
	long long		width;
	int				flags;
	int				negative;
	size_t			size;
}					t_index;

int					ft_printf(const char *format, ...);
size_t				parser(const char *format, size_t *head, va_list *args);
int					dispatcher(char c, va_list *args, t_index *params);

int					baker_char(char c, t_index *params);
int					baker_string(char *s, t_index *params);
int					baker_pointer(void *p, t_index *params);
int					baker_int(int n, t_index *params);
int					baker_long(long n, t_index *params);
int					baker_longlong(long long n, t_index *params);
int					baker_double(double n, t_index *params);
int					baker_longdouble(long double n, t_index *params);

int					printer_arg(const char *s, const char c, t_index *params);
size_t				printer_fmt(const char *format,
									size_t *head,
									va_list *args);
int					printer_filler(char c, long long len);

void				special_handler(const char *s,
									const char c,
									t_index *params);
int					prefix(t_index *params,
						const char *s,
						const char type,
						int print);
int					width(const char *s,
							const char c,
							t_index *params,
							int print);
int					int_precision(t_index *params);
int					float_precision(const char *s, t_index *params);
size_t				find_point(const char *s);

int					check_flag(const char c, t_index *params);
int					check_length(const char *format,
									size_t *head,
									t_index *params);
int					check_width(const char *format,
									size_t *head,
									t_index *params);
int					check_precision(const char *format,
									size_t *head,
									t_index *params);

#endif
