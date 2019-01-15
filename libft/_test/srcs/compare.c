#include "libft_tests.h"

void	ft_putmem(void *s, size_t n)
{
	size_t	i;

	i = 0;

	if (n == 4)
	{
			if (s == NULL)
				return ;
			printf("%d", *(int*)s);
	}
	else
	{
		while (i < n)
		{
			if (*(unsigned char*)(s + i) == 0)
				printf("0");
			else
				printf("%c", *(unsigned char*)(s + i));
			i++;
		}
	}
	printf("\n");
}

void	ft_memdiff(void *s1, void *s2, void *s3, char* msg, size_t n)
{
	size_t i;
	char *spaces;

	spaces = ft_strnew(200);

	i = 0;
	printf("[%s]", msg);
	while(i < n)
	{
		if 	(*(unsigned char*)(s1 + i) != *(unsigned char*)(s2 + i))
		{
			memset(spaces, ' ', 60 - strlen(msg));
			printf("%s", spaces);
			printf("-----KO-----\n\n");
			printf("original string : "); ft_putmem(s3, n); printf("\n");
			printf("expected output : "); ft_putmem(s1, n); printf("\n");
			printf("    your output : "); ft_putmem(s2, n); printf("\n");
			return;
		}
		i++;
	}
	memset(spaces, ' ', 62 - strlen(msg));
	printf("%s", spaces);
	printf("|||OK|||\n");
}
