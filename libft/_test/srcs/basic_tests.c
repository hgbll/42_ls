#include "libft_tests.h"

#define SIZE 100

//___________________________HELPER FUNCTIONS__________________________________


static void plusone(char *c)
{
	*c += 1;
}

static void plusone_upper(unsigned int i, char *c)
{
	if (i)
		*c += 1;
	else
		*c -= 'a' - 'A' - 1;
}

static char plusone_ret(char c)
{
	c += 1;
	return (c);
}

static char plusone_upper_ret(unsigned int i, char c)
{
	if (i)
		c += 1;
	else
		c -= 'a' - 'A' - 1;
	return (c);
}

static void	ft_initmem(void *s1, void *s2, void *s3)
{
	bzero(s1, SIZE);
	bzero(s2, SIZE);
	bzero(s3, SIZE);
}

void		basic_tests(void)
{
//	VARIABLES
	int 	i;
	int		a;
	int		b;
	int 	fd;
	char	buf[SIZE];
	char	*s1; s1 = (char*)malloc(SIZE);
	char	*s2; s2 = (char*)malloc(SIZE);
	char	*s3; s3 = (char*)malloc(SIZE);

	ft_initmem(s1, s2, s3);
	bzero(buf, SIZE);
	i = 0;
	a = 0;
	b = 0;
	fd = 0;

//	START
	ft_putstr("_________________________________LIBFT_TEST_____________________________\n");
//	STR FUNCTIONS
//	STRLEN
	printf("\n\nSTRLEN\n");
	printf("_______________________________________________________________\n");
	
	a = strlen("");
	b = ft_strlen("");
	ft_memdiff(&a, &b, NULL, "str vide", sizeof(int));
	a = strlen("dsdjfsa;jf;ajsfd");
	b = ft_strlen("dsdjfsa;jf;ajsfd");
	ft_memdiff(&a, &b, NULL, "str standard", sizeof(int));
	
//	STRDUP
	printf("\nSTRDUP\n");
	printf("_______________________________________________________________\n");

	ft_initmem(s1, s2, s3);
	strcpy(s1, strdup(""));
	strcpy(s2, ft_strdup(""));
	strcpy(s3, strdup(""));
	ft_memdiff(s1, s2, s3, "empty str", SIZE);
	
	ft_initmem(s1, s2, s3);
	strcpy(s1, strdup("dklsajkdflajdflj"));
	strcpy(s2, ft_strdup("dklsajkdflajdflj"));
	strcpy(s3, strdup("dklsajkdflajdflj"));
	ft_memdiff(s1, s2, s3, "filled str", SIZE);

//	STRCPY
	printf("\nSTRCPY\n");
	printf("_______________________________________________________________\n");
	
	ft_initmem(s1, s2, s3);
	strcpy(s1, "bonjour");
	strcpy(s2, "bonjour");
	strcpy(s3, "bonjour");
	
	strcpy(s1, "");
	ft_strcpy(s2, "");
	ft_memdiff(s1, s2, s3, "empty str > str", SIZE);
	
	ft_initmem(s1, s2, s3);
	
	strcpy(s1, "");
	ft_strcpy(s2, "");
	ft_memdiff(s1, s2, s3, "empty str > empty str", SIZE);
	
	ft_initmem(s1, s2, s3);
	strcpy(s1, "lorem");
	strcpy(s2, "ipsum");
	strcpy(s3, "lorem");
	
	strcpy(s1, s3);
	ft_strcpy(s2, s3);
	ft_memdiff(s1, s2, s3, "str > str", SIZE);
	
//	STRNCPY
	printf("\nSTRNCPY\n");
	printf("_______________________________________________________________\n");

	s1 = (char*)malloc(SIZE);
	s2 = (char*)malloc(SIZE);
	s3 = (char*)malloc(SIZE);

	ft_initmem(s1, s2, s3);
	memset(s1, 'A', SIZE);
	memset(s2, 'A', SIZE);
	memset(s3, 'B', SIZE);
	strncpy(s1, s3, 0);
	ft_strncpy(s2, s3, 0);
	ft_memdiff(s1, s2, s3, "len = 0", SIZE);

	ft_initmem(s1, s2, s3);
	memset(s1, 'A', SIZE);
	memset(s2, 'A', SIZE);
	memset(s3, 'B', SIZE);
	strncpy(s1, s3, 2 * SIZE);
	ft_strncpy(s2, s3, 2 * SIZE);
	ft_memdiff(s1, s2, s3, "len > src len", SIZE);
	
	ft_initmem(s1, s2, s3);
	memset(s1, 'A', SIZE);
	memset(s2, 'A', SIZE);
	memset(s3, 'B', SIZE);
	strncpy(s1, s3, 2 * SIZE);
	ft_strncpy(s2, s3, 2 * SIZE);
	ft_memdiff(s1, s2, s3, "len > src len, len > dst len", SIZE);
	
	ft_initmem(s1, s2, s3);
	memset(s1, 'A', SIZE);
	memset(s2, 'A', SIZE);
	strncpy(s1, s3, SIZE / 2);
	ft_strncpy(s2, s3, SIZE / 2);
	ft_memdiff(s1, s2, s3, "len > src len (src empty)", SIZE);
	
	ft_initmem(s1, s2, s3);
	memset(s1, 'A', SIZE);
	memset(s2, 'A', SIZE);
	memset(s3, 'B', SIZE);
	strncpy(s1, s3, SIZE / 2);
	ft_strncpy(s2, s3, SIZE / 2);
	ft_memdiff(s1, s2, s3, "len < src len", SIZE);

	ft_initmem(s1, s2, s3);
	memset(s3, 'B', SIZE);
	strncpy(s1, s3, SIZE / 2);
	ft_strncpy(s2, s3, SIZE / 2);
	ft_memdiff(s1, s2, s3, "len < src len (dst empty)", SIZE);
	
	ft_initmem(s1, s2, s3);
	memset(s1, 'A', SIZE);
	memset(s2, 'A', SIZE);
	memset(s3, 'B', SIZE);
	strncpy(s1, s3, SIZE);
	ft_strncpy(s2, s3, SIZE);
	ft_memdiff(s1, s2, s3, "len = src len", SIZE);

//	STRNEW
	printf("\nSTRNEW\n");
	printf("_______________________________________________________________\n");

	s1 = (char*)malloc(SIZE);
	s2 = (char*)malloc(SIZE);
	s3 = (char*)malloc(SIZE);
	ft_initmem(s1, s2, s3);
	memset(s2, 'A', SIZE - 1);
	s2 = ft_strnew(SIZE);
	ft_memdiff(s1, s2, s3, "str is filled with \\0", SIZE);
	
	s1 = (char*)malloc(1);
	s3 = (char*)malloc(1);
	memset(s1, '\0', 1);
	memset(s3, '\0', 1);
	s2 = ft_strnew(0);
	ft_memdiff(s1, s2, s3, "size is 0", 1);

//	STRDEL
	printf("\nSTRDEL\n");
	printf("_______________________________________________________________\n");

	s2 = (char*)malloc(SIZE);
	char	**delptr;
	memset(s2, 'A', SIZE - 1);
	delptr = &s2;
	ft_strdel(delptr);
	if (s2 == NULL)
		printf("[null ptr returned]                                             |||OK|||\n");
	else 
		printf("[null ptr returned]                                           -----KO-----\n");

//	STRCLR
	printf("\nSTRCLR\n");
	printf("_______________________________________________________________\n");

	s1 = (char*)malloc(SIZE);
	s2 = (char*)malloc(SIZE);
	s3 = (char*)malloc(SIZE);
	ft_initmem(s1, s2, s3);
	memset(s2, 'A', SIZE - 1);
	ft_strclr(s2);
	ft_memdiff(s1, s2, s3, "str is filled with \\0", SIZE);

//	STREQU
	printf("\nSTREQU\n");
	printf("_______________________________________________________________\n");

	s1 = ft_strnew(SIZE);
	s2 = ft_strnew(SIZE);
	ft_strcpy(s3, "");
	ft_strcpy(s1, "bonjour");
	ft_strcpy(s2, "bonjour");
	a = ft_strequ(s1, s2);
	b = 1;
	ft_memdiff(&b, &a, NULL, "s1 = s2 (not empty)", sizeof(int));
	
	s1[0] = '\0';
	s2[0] = '\0';
	a = ft_strequ(s1, s2);
	b = 1;
	ft_memdiff(&b, &a, NULL, "s1 = s2 (empty)", sizeof(int));
	
	strcpy(s1, "fdsfojfjoiejifwd");
	strcpy(s2, "bonjour");
	a = ft_strequ(s1, s2);
	b = 0;
	ft_memdiff(&b, &a, NULL, "s1 != s2", sizeof(int));

	strcpy(s1, "fdsfojf");
	strcpy(s2, "bonjour");
	a = ft_strequ(s1, s2);
	b = 0;
	ft_memdiff(&b, &a, NULL, "s1 != s2 (same size)", sizeof(int));
	
	strcpy(s1, "");
	strcpy(s2, "bonjour");
	a = ft_strequ(s1, s2);
	b = 0;
	ft_memdiff(&b, &a, NULL, "s1 != s2 (one is empty)", sizeof(int));

//	STRNEQU
	printf("\nSTRNEQU\n");
	printf("_______________________________________________________________\n");

	s1 = ft_strnew(SIZE);
	s2 = ft_strnew(SIZE);
	ft_strcpy(s3, "");
	ft_strcpy(s1, "bonjour");
	ft_strcpy(s2, "bonjour");
	a = ft_strnequ(s1, s2, 50);
	b = 1;
	ft_memdiff(&b, &a, NULL, "s1 = s2 (same size, n = 50)", sizeof(int));

	ft_strcpy(s3, "");
	ft_strcpy(s1, "bonjour");
	ft_strcpy(s2, "bonjour");
	a = ft_strnequ(s1, s2, 50);
	b = 1;
	ft_memdiff(&b, &a, NULL, "s1 = s2 (same size, n = 3)", sizeof(int));
	
	ft_strcpy(s3, "");
	ft_strcpy(s1, "hello");
	ft_strcpy(s2, "hellohowareyou");
	a = ft_strnequ(s1, s2, 5);
	b = 1;
	ft_memdiff(&b, &a, NULL, "s1 = s2 for 5 char then != (different size, n = 5)", sizeof(int));
	
	ft_strcpy(s3, "");
	ft_strcpy(s1, "hellohiiiiiiii");
	ft_strcpy(s2, "hellohowareyou");
	a = ft_strnequ(s1, s2, 50);
	b = 0;
	ft_memdiff(&b, &a, NULL, "s1 = s2 for 5 char then != (same size, n = 50)", sizeof(int));
	
	ft_strcpy(s3, "");
	ft_strcpy(s1, "bonjour");
	ft_strcpy(s2, "bonjour");
	a = ft_strnequ(s1, s2, 0);
	b = 1;
	ft_memdiff(&b, &a, NULL, "s1 = s2 (same size, n = 0)", sizeof(int));

	s1[0] = '\0';
	s2[0] = '\0';
	a = ft_strnequ(s1, s2, 2);
	b = 1;
	ft_memdiff(&b, &a, NULL, "s1 = s2 (empty, n = 2)", sizeof(int));

	strcpy(s1, "fdsfojfjoiejifwd");
	strcpy(s2, "bonjour");
	a = ft_strnequ(s1, s2, 50);
	b = 0;
	ft_memdiff(&b, &a, NULL, "s1 != s2 (n = 50)", sizeof(int));

	strcpy(s1, "");
	strcpy(s2, "bonjour");
	a = ft_strnequ(s1, s2, 50);
	b = 0;
	ft_memdiff(&b, &a, NULL, "s1 != s2 (one is empty, n = 50)", sizeof(int));

//	STRITER
	printf("\nSTRITER\n");
	printf("_______________________________________________________________\n");

	ft_initmem(s1, s2, s3);	
	strcpy(s1, "bcdefghi");
	strcpy(s2, "abcdefgh");
	strcpy(s3, "abcdefgh");
	ft_striter(s2, plusone);
	ft_memdiff(s1, s2, s3, "adding 1 to every char in str", SIZE);

	ft_initmem(s1, s2, s3);
	ft_striter(s2, plusone);
	ft_memdiff(s1, s2, s3, "empty str", SIZE);

//	STRITERI
	printf("\nSTRITERI\n");
	printf("_______________________________________________________________\n");
	
	strcpy(s1, "Bcdefghi");
	strcpy(s2, "abcdefgh");
	strcpy(s3, "abcdefgh");
	ft_striteri(s2, plusone_upper);
	ft_memdiff(s1, s2, s3, "adding 1 to every char + capitalize s[0]", SIZE);

	ft_initmem(s1, s2, s3);
	ft_striteri(s2, plusone_upper);
	ft_memdiff(s1, s2, s3, "empty str", SIZE);

//	STRJOIN
	printf("\nSTRJOIN\n");
	printf("_______________________________________________________________\n");
	
	strcpy(s1, "Je m'presente, je m'appelle Henri");
	s2 = NULL;
	strcpy(s3, "Je m'presente, je m'appelle");
	s2 = ft_strjoin(s3, " Henri");
	ft_memdiff(s1, s2, s3, "standard behavior", sizeof("Je m'presente, je m'appelle Henri") + 1);

	strcpy(s1, "Hello is it me you're looking for");
	s2 = NULL;
	strcpy(s3, "Hello is it me you're looking for");
	s2 = ft_strjoin(s3, "");
	ft_memdiff(s1, s2, s3, "join filled to empty", sizeof("Hello is it me you're looking for") + 1);
	
	s2 = NULL;
	s2 = ft_strjoin("", s3);
	ft_memdiff(s1, s2, s3, "join empty to filled", sizeof("Hello is it me you're looking for") + 1);
	
	strcpy(s1, "");
	s2 = NULL;
	strcpy(s3, "");
	s2 = ft_strjoin(s3, s1);
	ft_memdiff(s1, s2, s3, "join 2 empty strings", 1);

//	STRSUB
	printf("\nSTRSUB\n");
	printf("_______________________________________________________________\n");
	
	strcpy(s1, "victoire");
	s2 = NULL;
	strcpy(s3, "en avant pour la victoire, pooooooo keeeee mooooooooooon");
	s2 = ft_strsub(s3, 17, 8);
	ft_memdiff(s1, s2, s3, "substring is valid, len = 8", 9);

	strcpy(s1, "victoire");
	s2 = NULL;
	strcpy(s3, "en avant pour la victoire");
	s2 = ft_strsub(s3, 17, 8);
	ft_memdiff(s1, s2, s3, "substring is valid and at the end of source", 9);
	
	strcpy(s1, "victoire");
	s2 = NULL;
	strcpy(s3, "victoire, victoire, victoire");
	s2 = ft_strsub(s3, 0, 8);
	ft_memdiff(s1, s2, s3, "substring is valid and at the beginning of source", 9);
	
	strcpy(s1, "victoire");
	s2 = NULL;
	strcpy(s3, "victoire");
	s2 = ft_strsub(s3, 0, 8);
	ft_memdiff(s1, s2, s3, "substring = source", 9);

//	STRMAP
	printf("\nSTRMAP\n");
	printf("_______________________________________________________________\n");
	
	ft_initmem(s1, s2, s3);
	strcpy(s1, "bcdefghi");
	s2 = NULL;
	strcpy(s3, "abcdefgh");
	s2 = ft_strmap(s3, plusone_ret);
	ft_memdiff(s1, s2, s3, "adding 1 to every char in str", 10);

	ft_initmem(s1, s2, s3);
	strcpy(s1, "");
	s2 = NULL;
	strcpy(s3, "");
	s2 = ft_strmap(s3, plusone_ret);
	ft_memdiff(s1, s2, s3, "empty str", 10);

//	STRMAPI
	printf("\nSTRMAPI\n");
	printf("_______________________________________________________________\n");
	
	strcpy(s1, "Bcdefghi");
	s2 = NULL;
	strcpy(s3, "abcdefgh");
	s2 = ft_strmapi(s3, plusone_upper_ret);
	ft_memdiff(s1, s2, s3, "adding 1 to every char in str + capitalize s[0]", 9);
	strncpy(s2, s1, 9);

	ft_initmem(s1, s2, s3);
	strcpy(s1, "");
	s2 = NULL;
	strcpy(s3, "");
	s2 = ft_strmapi(s3, plusone_upper_ret);
	ft_memdiff(s1, s2, s3, "empty str", 8);

	//STRCAT
	printf("\nSTRCAT\n");
	printf("_______________________________________________________________\n");
	
	s1 = (char*)malloc(SIZE);
	s2 = (char*)malloc(SIZE);
	s3 = (char*)malloc(SIZE);
	
	ft_initmem(s1, s2, s3);
	strcpy(s1, "hello");
	strcpy(s2, "hello");
	strcpy(s3, "goodbye");
	strcat(s1, s3);
	ft_strcat(s2, s3);
	ft_memdiff(s1, s2, s3, "dst < src (both not empty)", SIZE);
	
	ft_initmem(s1, s2, s3);
	strcpy(s1, "");
	strcpy(s2, "");
	strcpy(s3, "goodbye");
	strcat(s1, s3);
	ft_strcat(s2, s3);
	ft_memdiff(s1, s2, s3, "dst < src (dst empty)", SIZE);
	
	ft_initmem(s1, s2, s3);
	strcpy(s1, "hello");
	strcpy(s2, "hello");
	strcpy(s3, "");
	strcat(s1, s3);
	ft_strcat(s2, s3);
	ft_memdiff(s1, s2, s3, "dst < src (src empty)", SIZE);

	memset(s1, 'A', SIZE);
	memset(s2, 'A', SIZE);
	memset(s3, 'A', SIZE);
	strcpy(s1, "hello");
	strcpy(s2, "hello");
	strcpy(s3, "goodbye");
	strcat(s1, s3);
	ft_strcat(s2, s3);
	ft_memdiff(s1, s2, s3, "dst < src (src empty)", SIZE);

	//STRCHR
	printf("\nSTRCHR\n");
	printf("_______________________________________________________________\n");
	
	s3 = (char*)malloc(SIZE);

	strcpy(s3, "all your bases are belong to us");
	s1 = strchr(s3, 'b');
   	s2 = ft_strchr(s3, 'b');
	if (s2 == NULL)
		printf("[(return is NULL, should be not NULL)]                        -----KO-----\n");
	else
		ft_memdiff(s1, s2, s3, "find letter in filled string (return is not NULL)", SIZE);

	s1 = strchr(s3, 'i');
   	s2 = ft_strchr(s3, 'i');
	if (s2 != NULL && s1 != NULL)
		printf("[find letter in filled string (return is NULL)]               -----KO-----\n");
	else
		printf("[find letter in filled string (return is NULL)]                 |||OK|||\n");

	s1 = strchr(s3, '\0');
   	s2 = ft_strchr(s3, '\0');
	if (s2 == NULL)
		printf("[return is NULL, should be not NULL]                          -----KO-----\n");
	else
		ft_memdiff(s1, s2, s3, "find \\0 in filled string", SIZE);
	
	bzero(s3, SIZE);
	
	s1 = strchr(s3, '\0');
   	s2 = ft_strchr(s3, '\0');
	if (s2 == NULL)
		printf("[(return is NULL, should be not NULL)]                        -----KO-----\n");
	else
		ft_memdiff(s1, s2, s3, "find \\0 in empty string", SIZE);

	s1 = strchr(s3, 'b');
   	s2 = ft_strchr(s3, 'b');
	if (s2 != NULL && s1 != NULL)
		printf("[find letter in empty string (return is NULL)]                -----KO-----\n");
	else
		printf("[find letter in empty string (return is NULL)]                  |||OK|||\n");

	//STRRCHR
	printf("\nSTRRCHR\n");
	printf("_______________________________________________________________\n");
	
	s3 = (char*)malloc(SIZE);

	strcpy(s3, "all your bases are belong to us");
	s1 = strrchr(s3, 'b');
   	s2 = ft_strrchr(s3, 'b');
	if (s2 == NULL)
		printf("[(return is NULL, should be not NULL)]                        -----KO-----\n");
	else
		ft_memdiff(s1, s2, s3, "find letter in filled string (return is not NULL)", SIZE);

	s1 = strrchr(s3, 'i');
   	s2 = ft_strrchr(s3, 'i');
	if (s2 != NULL && s1 != NULL)
		printf("[find letter in filled string (return is NULL)]               -----KO-----\n");
	else
		printf("[find letter in filled string (return is NULL)]                 |||OK|||\n");

	s1 = strrchr(s3, '\0');
   	s2 = ft_strrchr(s3, '\0');
	if (s2 == NULL)
		printf("[return is NULL, should be not NULL]                          -----KO-----\n");
	else
		ft_memdiff(s1, s2, s3, "find \\0 in filled string", SIZE);
	
	bzero(s3, SIZE);
	
	s1 = strrchr(s3, '\0');
   	s2 = ft_strrchr(s3, '\0');
	if (s2 == NULL)
		printf("[(return is NULL, should be not NULL)]                        -----KO-----\n");
	else
		ft_memdiff(s1, s2, s3, "find \\0 in empty string", SIZE);

	s1 = strrchr(s3, 'b');
   	s2 = ft_strrchr(s3, 'b');
	if (s2 != NULL && s1 != NULL)
		printf("[find letter in empty string (return is NULL)]                -----KO-----\n");
	else
		printf("[find letter in empty string (return is NULL)]                  |||OK|||\n");

	//STRSTR
	printf("\nSTRSTR\n");
	printf("_______________________________________________________________\n");

	s1 = (char*)malloc(SIZE);
	s2 = (char*)malloc(SIZE);
	s3 = (char*)malloc(SIZE);
	
	ft_initmem(s1, s3, s3);
	strcpy(s1, strstr("all work and no play makes jack a dull boy", "jack"));
	strcpy(s2, ft_strstr("all work and no play makes jack a dull boy", "jack"));
	if (s2 == NULL)
		printf("[(return is NULL, should be not NULL)]                        -----KO-----\n");
	else
		ft_memdiff(s1, s2, s3, "find str in filled str, 1 match", SIZE);

	ft_initmem(s1, s3, s3);
	strcpy(s1, strstr("all jack and no play makes jack a dull boy", "jack"));
	strcpy(s2, ft_strstr("all jack and no play makes jack a dull boy", "jack"));
	if (s2 == NULL)
		printf("[(return is NULL, should be not NULL)]                        -----KO-----\n");
	else
		ft_memdiff(s1, s2, s3, "find str in filled str, 2 matches", SIZE);

	ft_initmem(s1, s3, s3);
	strcpy(s1, strstr("all jack and no play makes jack a dull boy", ""));
	strcpy(s2, ft_strstr("all jack and no play makes jack a dull boy", ""));
	if (s2 == NULL)
		printf("[(return is NULL, should be not NULL)]                        -----KO-----\n");
	else
		ft_memdiff(s1, s2, s3, "find str in filled str, needle empty", SIZE);
	
	s1 = strstr("all work and no play makes jac a dull boy", "jack");
	s2 = ft_strstr("all work and no play makes jac a dull boy", "jack");
	if (s2 != NULL && s1 != NULL)
		printf("[find str in filled str, 0 match]                             -----KO-----\n");
	else
		printf("[find str in filled str, 0 match]                               |||OK|||\n");
	
	s1 = strstr("", "");
	s2 = ft_strstr("", "");
	if (s2[0] != '\0')
		printf("[find str in str, both empty]                                 -----KO-----\n");
	else
		printf("[find str in str, both empty]                                   |||OK|||\n");
	
	s1 = strstr("", "jack");
	s2 = ft_strstr("", "jack");
	if (s2 != NULL && s1 != NULL)
		printf("[find str in empty str]                                       -----KO-----\n");
	else
		printf("[find str in empty str]                                         |||OK|||\n");
	
//	MEM FUNCTIONS
//	BZERO
	printf("\nBZERO\n");
	printf("_______________________________________________________________\n");
	
	s1 = (char*)malloc(SIZE);
	s2 = (char*)malloc(SIZE);
	s3 = (char*)malloc(SIZE);

	ft_initmem(s1, s3, s3);
	memset(s1, 'A', SIZE);
	memset(s2, 'A', SIZE);
	memset(s3, 'A', SIZE);
	bzero(s1, SIZE);
	ft_bzero(s2, SIZE);
	ft_memdiff(s1, s2, s3, "reset 100 bytes", SIZE);

	ft_initmem(s1, s3, s3);
	memset(s1, 'A', SIZE);
	memset(s2, 'A', SIZE);
	memset(s3, 'A', SIZE);
	bzero(s1, 0);
	ft_bzero(s2, 0);
	ft_memdiff(s1, s2, s3, "set 0 bytes", SIZE);

//	MEMSET
	printf("\nMEMSET\n");
	printf("_______________________________________________________________\n");
	
	ft_initmem(s1, s2, s3);
	memset(s1, 'A', SIZE);
	ft_memset(s2, 'A', SIZE);
	ft_memdiff(s1, s2, s3, "set 100 bytes", SIZE);

	ft_initmem(s1, s2, s3);
	memset(s1, 'A', 0);
	ft_memset(s2, 'A', 0);
	ft_memdiff(s1, s2, s3, "set 0 bytes", SIZE);
	
//	MEMMOVE
	printf("\nMEMMOVE\n");
	printf("_______________________________________________________________\n");

	s1 = (char*)malloc(SIZE);
	s2 = (char*)malloc(SIZE);
	s3 = (char*)malloc(SIZE);
	
	memset(&s1[20], '\\', 10);
	memset(&s1[30], '/', 10);
	memset(&s2[20], '\\', 10);
	memset(&s2[30], '/', 10);
	memset(&s3[20], '\\', 10);
	memset(&s3[30], '/', 10);
	memmove(&s1[50], &s1[20], 20);
	ft_memmove(&s2[50], &s2[20], 20);
	ft_memdiff(s1, s2, s3, "dst > src no overlap", SIZE);

	ft_initmem(s1, s2, s3);
	memset(&s1[20], '\\', 10);
	memset(&s1[30], '/', 10);
	memset(&s2[20], '\\', 10);
	memset(&s2[30], '/', 10);
	memset(&s3[20], '\\', 10);
	memset(&s3[30], '/', 10);
	memmove(&s1[23], &s1[20], 20);
	ft_memmove(&s2[23], &s2[20], 20);
	ft_memdiff(s1, s2, s3, "dst > src partial overlap", SIZE);
	
	ft_initmem(s1, s2, s3);
	memset(&s1[20], '\\', 10);
	memset(&s1[30], '/', 10);
	memset(&s2[20], '\\', 10);
	memset(&s2[30], '/', 10);
	memset(&s3[20], '\\', 10);
	memset(&s3[30], '/', 10);
	memmove(&s1[20], &s1[20], 20);
	ft_memmove(&s2[20], &s2[20], 20);
	ft_memdiff(s1, s2, s3, "dst = src full overlap", SIZE);

	ft_initmem(s1, s2, s3);
	memset(&s1[20], '\\', 10);
	memset(&s1[30], '/', 10);
	memset(&s2[20], '\\', 10);
	memset(&s2[30], '/', 10);
	memset(&s3[20], '\\', 10);
	memset(&s3[30], '/', 10);
	memmove(&s1[0], &s1[20], 10);
	ft_memmove(&s2[0], &s2[20], 10);
	ft_memdiff(s1, s2, s3, "dst < src no overlap", SIZE);
	
	ft_initmem(s1, s2, s3);
	memset(&s1[20], '\\', 10);
	memset(&s1[30], '/', 10);
	memset(&s2[20], '\\', 10);
	memset(&s2[30], '/', 10);
	memset(&s3[20], '\\', 10);
	memset(&s3[30], '/', 10);
	memmove(&s1[10], &s1[20], 20);
	ft_memmove(&s2[10], &s2[20], 20);
	ft_memdiff(s1, s2, s3, "dst < src partial overlap", SIZE);

//	MEMCMP
	printf("\nMEMCMP\n");
	printf("_______________________________________________________________\n");

	ft_initmem(s1, s2, s3);
	a = memcmp(s1, s2, 0);
	b = ft_memcmp(s1, s2, 0);
	ft_memdiff(&a, &b, NULL, "compare 0 bytes", sizeof(a));

	strcpy(s1, "dfkljsafhjkdh");
	strcpy(s2, "dfkljsafhjkd\n");
	ft_initmem(s1, s2, s3);
	a = memcmp(s1, s2, 0);
	b = ft_memcmp(s1, s2, 0);
	ft_memdiff(&a, &b, NULL, "compare 100 bytes", sizeof(a));

	bzero(s1, SIZE);
	strcpy(s2, "dfkljsafhjkd\n");
	ft_initmem(s1, s2, s3);
	a = memcmp(s1, s2, 0);
	b = ft_memcmp(s1, s2, 0);
	ft_memdiff(&a, &b, NULL, "compare, 1 string empty", sizeof(a));
	
	bzero(s2, SIZE);
	ft_initmem(s1, s2, s3);
	a = memcmp(s1, s2, 0);
	b = ft_memcmp(s1, s2, 0);
	ft_memdiff(&a, &b, NULL, "compare, 2 strings empty", sizeof(a));

}
