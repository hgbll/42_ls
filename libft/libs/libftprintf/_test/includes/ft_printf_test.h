/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:37:12 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 14:36:25 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TEST_H
# define FT_PRINTF_TEST_H

# include "stdio.h"
# include "limits.h"
# include "libft.h"

int		ft_printf(const char *format, ...);
void	debug_print_memory(void);
void		test_int(int (*f)(const char*, ...));
void		test_double(int (*f)(const char*, ...));
void		test_string(int (*f)(const char*, ...));

void		loop_short(int (*f)(const char*, ...), char *fmt,
				short min, short max,
				unsigned long long imax);
void		loop_int(int (*f)(const char*, ...), char *fmt,
				int min, int max,
				unsigned long long imax);
void		loop_long(int (*f)(const char*, ...), char *fmt,
				long min, long max,
				unsigned long long imax);
void		loop_llong(int (*f)(const char*, ...), char *fmt,
				long long min, long long max,
				unsigned long long imax);
void		loop_uint(int (*f)(const char*, ...), char *fmt,
				unsigned int min, unsigned int max,
				unsigned long long imax);
void		loop_ulong(int (*f)(const char*, ...), char *fmt,
				unsigned long min, unsigned long max,
				unsigned long long imax);
void		loop_ullong(int (*f)(const char*, ...), char *fmt,
				unsigned long long min, unsigned long long max,
				unsigned long long imax);
void		loop_double(int (*f)(const char*, ...), char *fmt,
				double min, double max, double step,
				unsigned long long imax);

#endif
