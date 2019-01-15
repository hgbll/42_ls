#include "libft_tests.h"

void		custom_tests(void)
{
	int aint;
	long along;

	printf("\nATOI\n");
	printf("_______________________________________________________________\n");


	aint = ft_atoi("2147483647");
	printf("%d\n", INT_MAX);
	printf("%d\n", aint);

	aint = ft_atoi("-2147483648");
	printf("%d\n", INT_MIN);
	printf("%d\n", aint);

	aint = ft_atoi("2147483648");
	printf("0 : %d\n", aint);
	
	aint = ft_atoi("99999999999999999999999999999");
	printf("0 : %d\n", aint);

	aint = ft_atoi("-2147483649");
	printf("0 : %d\n", aint);

	aint = ft_atoi("-99999999999999999999999999999");
	printf("0 : %d\n", aint);

	aint = ft_atoi("0");
	printf("0 : %d\n", aint);
	
	aint = ft_atoi("987654321");
	printf("arbitrary : %d\n", aint);

	printf("\nATOL\n");
	printf("_______________________________________________________________\n");


	along = ft_atol("9223372036854775807");
	printf("%ld\n", LONG_MAX);
	printf("%ld\n", along);

	along = ft_atol("-9223372036854775808");
	printf("%ld\n", LONG_MIN);
	printf("%ld\n", along);

	along = ft_atol("9223372036854775808");
	printf("0 : %ld\n", along);
	
	along = ft_atol("99999999999999999999999999999");
	printf("0 : %ld\n", along);

	along = ft_atol("-9223372036854775809");
	printf("0 : %ld\n", along);

	along = ft_atol("-99999999999999999999999999999");
	printf("0 : %ld\n", along);

	along = ft_atol("0");
	printf("0 : %ld\n", along);
	
	along = ft_atol("987654321097654321");
	printf("arbitrary : %ld\n", along);
	
	printf("\nITOA\n");
	printf("_______________________________________________________________\n");

	printf("%s\n%s\n--\n", "0", ft_itoa(0));
	printf("%s\n%s\n--\n", "2147483647", ft_itoa(INT_MAX));
	printf("%s\n%s\n--\n", "-2147483648", ft_itoa(INT_MIN));
	printf("%s\n%s\n--\n", "987654321", ft_itoa(987654321));
	printf("%s\n%s\n--\n", "-987654321", ft_itoa(-987654321));

	printf("\nLTOA\n");
	printf("_______________________________________________________________\n");

	along = LONG_MAX;
	printf("%s\n%s\n--\n", "0", ft_ltoa(0L));
	printf("%s\n%s\n--\n", "9223372036854775807", ft_ltoa(LONG_MAX));
	printf("%s\n%s\n--\n", "-9223372036854775808", ft_ltoa(LONG_MIN));
	printf("%s\n%s\n--\n", "987654321097654321", ft_ltoa(987654321097654321L));
	printf("%s\n%s\n--\n", "-987654321097654321", ft_ltoa(-987654321097654321L));

	printf("\nUITOXA\n");
	printf("_______________________________________________________________\n");

	unsigned int 	a_uint = 0;
	char 			*s1;
	char			*s2;
	s2 = ft_strnew(100);

	a_uint = 0;
	while (a_uint < 100000)
	{
		s1 = ft_uitoxa(a_uint, 1);
		sprintf(s2, "%X", a_uint);
		if (strcmp(s1, s2))
		{
			printf("error with %u\n", a_uint);
			printf("%s\n", s1);
			printf("%s\n", s2);
		}
		a_uint++;
	}
	a_uint = UINT_MAX;
	while (a_uint > UINT_MAX - 100000)
	{
		s1 = ft_uitoxa(a_uint, 1);
		sprintf(s2, "%X", a_uint);
		if (strcmp(s1, s2))
		{
			printf("error with %u\n", a_uint);
			printf("%s\n", s1);
			printf("%s\n", s2);
		}
		a_uint--;
	}

	printf("OK\n");
	printf("\nUITOOA\n");
	printf("_______________________________________________________________\n");

	a_uint = 0;
	while (a_uint < 100000)
	{
		s1 = ft_uitooa(a_uint);
		sprintf(s2, "%o", a_uint);
		if (strcmp(s1, s2))
		{
			printf("error with %u\n", a_uint);
			printf("%s\n", s1);
			printf("%s\n", s2);
		}
		a_uint++;
	}
	a_uint = UINT_MAX;
	while (a_uint > UINT_MAX - 100000)
	{
		s1 = ft_uitooa(a_uint);
		sprintf(s2, "%o", a_uint);
		if (strcmp(s1, s2))
		{
			printf("error with %u\n", a_uint);
			printf("%s\n", s1);
			printf("%s\n", s2);
		}
		a_uint--;
	}
	printf("OK\n");

	printf("\nDTOA\n");
	printf("_______________________________________________________________\n");
	
	printf("%s\n", ft_dtoa(DBL_MIN));
	printf("%s\n", ft_dtoa(4.55435));
	printf("%s\n", ft_dtoa(4304903940394349234808240.554353942849320));
	printf("%s\n", ft_dtoa(0));
	printf("%s\n", ft_dtoa(34834));
	printf("%s\n", ft_dtoa(-34));

	printf("\nROUND_DOUBLE\n");
	printf("_______________________________________________________________\n");
	
	printf("%s\n", ft_round_double(ft_dtoa(9999999.9), 0));
	printf("%s\n", ft_round_double(ft_dtoa(2.54439094), 0));
	printf("%s\n", ft_round_double(ft_dtoa(76.599999999999), 0));
	printf("%s\n", ft_round_double(ft_dtoa(34923), 1));
	printf("%s\n", ft_round_double(ft_dtoa(34923), 0));
	printf("%s\n", ft_round_double(ft_dtoa(0), 1));
	printf("%s\n", ft_round_double(ft_dtoa(0), 0));
//	printf("%s\n", ft_dtoa(4304903940394349234808240.554353942849320));
//	printf("%s\n", ft_dtoa(0));
//	printf("%s\n", ft_dtoa(34834));
//	printf("%s\n", ft_dtoa(-34));
}

