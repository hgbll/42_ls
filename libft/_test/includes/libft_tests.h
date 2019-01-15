#ifndef LIBFT_TESTS_H
# define LIBFT_TESTS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <strings.h>
#include <ctype.h>
#include <limits.h>
#include "libft.h"
#include <float.h>

void	basic_tests(void);
void	custom_tests(void);

void	ft_memdiff(void *s1, void *s2, void *s3, char* msg, size_t n);
void	ft_putmem(void *s, size_t n);

#endif
