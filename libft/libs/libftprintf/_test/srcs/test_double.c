#include "ft_printf_test.h"
#include <float.h>
#include <math.h>

void		test_double(int (*f)(const char*, ...))
{
	double				zero_double;
	unsigned long long  zero_ull;

	zero_ull = 0x8000000000000000ULL;
	zero_double = *((double*)(&zero_ull));

	f("%f\n", 1.0 / 0.0);
	f("%f\n", -1.0 / 0.0);
	f("%f\n", 0.0 / 0.0);

	f("%50f\n", 1.0 / 0.0);
	f("%50f\n", -1.0 / 0.0);
	f("%50f\n", 0.0 / 0.0);

	f("%.50f\n", 1.0 / 0.0);
	f("%.50f\n", -1.0 / 0.0);
	f("%.50f\n", 0.0 / 0.0);

	f("%.2f\n", 1.0 / 0.0);
	f("%.2f\n", -1.0 / 0.0);
	f("%.2f\n", 0.0 / 0.0);

	f("%0100.2f\n", zero_double);

}
