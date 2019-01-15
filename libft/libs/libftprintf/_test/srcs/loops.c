/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 12:27:14 by hbally            #+#    #+#             */
/*   Updated: 2018/12/31 13:30:36 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		loop_short(int (*f)(const char*, ...), char *fmt,
				short min, short max,
				unsigned long long imax)
{
	unsigned long long i;
	short step = max > min ? 1 : -1;

	i = 0;
	while ((min < max ? min < max : max < min) && (i < imax || imax == 0))
	{
		f(fmt, min);
		min += step;
		i++;
	}
	if (imax == 0)
		f(fmt, max);
}

void		loop_int(int (*f)(const char*, ...), char *fmt,
				int min, int max,
				unsigned long long imax)
{
	unsigned long long i;
	int step = max > min ? 1 : -1;

	i = 0;
	while ((min < max ? min < max : max < min) && (i < imax || imax == 0))
	{
		f(fmt, min);
		min += step;
		i++;
	}
	if (imax == 0)
	f(fmt, max);
}

void		loop_long(int (*f)(const char*, ...), char *fmt,
				long min, long max,
				unsigned long long imax)
{
	unsigned long long i;
	long step = max > min ? 1 : -1;
	
	i = 0;
	while ((min < max ? min < max : max < min) && (i < imax || imax == 0))
	{
		f(fmt, min);
		min += step;
		i++;
	}
	if (imax == 0)
	f(fmt, max);
}

void		loop_llong(int (*f)(const char*, ...), char *fmt,
				long long min, long long max,
				unsigned long long imax)
{
	unsigned long long i;
	long long step = max > min ? 1 : -1;

	i = 0;
	while ((min < max ? min < max : max < min) && (i < imax || imax == 0))
	{
		f(fmt, min);
		min += step;
		i++;
	}
	f(fmt, max);
}

void		loop_uint(int (*f)(const char*, ...), char *fmt,
				unsigned int min, unsigned int max,
				unsigned long long imax)
{
	unsigned long long i;
	unsigned int step = max > min ? 1 : -1;

	i = 0;
	while ((min < max ? min < max : max < min) && (i < imax || imax == 0))
	{
		f(fmt, min);
		min += step;
		i++;
	}
	f(fmt, max);
}

void		loop_ulong(int (*f)(const char*, ...), char *fmt,
				unsigned long min, unsigned long max,
				unsigned long long imax)
{
	unsigned long long i;
	unsigned long step = max > min ? 1 : -1;

	i = 0;
	while ((min < max ? min < max : max < min) && (i < imax || imax == 0))
	{
		f(fmt, min);
		min += step;
		i++;
	}
	f(fmt, max);
}

void		loop_ullong(int (*f)(const char*, ...), char *fmt,
				unsigned long long min, unsigned long long max,
				unsigned long long imax)
{
	unsigned long long i;
	unsigned long long step = max > min ? 1 : -1;

	i = 0;
	while ((min < max ? min < max : max < min) && (i < imax || imax == 0))
	{
		f(fmt, min);
		min += step;
		i++;
	}
	f(fmt, max);
}

void		loop_double(int (*f)(const char*, ...), char *fmt,
				double min, double max, double step,
				unsigned long long imax)
{
	unsigned long long i;

	i = 0;
	while ((min < max ? min < max : max < min) && (i < imax || imax == 0))
	{
		f(fmt, min);
		min += step;
		i++;
	}
	f(fmt, max);
}
