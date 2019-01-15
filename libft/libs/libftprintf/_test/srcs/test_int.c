#include "ft_printf_test.h"

void		test_int(int (*f)(const char*, ...))
{
	//BASIC

	loop_int(f, "%d\n", 0, INT_MAX, 10000llu);
	loop_int(f, "%d\n", 0, INT_MIN, 10000llu);
	loop_int(f, "%d\n", INT_MAX, 0, 10000llu);
	loop_int(f, "%d\n", INT_MIN, 0, 10000llu);

	loop_long(f, "%ld\n", 0, LONG_MAX, 10000llu);
	loop_long(f, "%ld\n", 0, LONG_MIN, 10000llu);
	loop_long(f, "%ld\n", LONG_MAX, 0, 10000llu);
	loop_long(f, "%ld\n", LONG_MIN, 0, 10000llu);

	loop_llong(f, "%lld\n", 0, LLONG_MAX, 10000llu);
	loop_llong(f, "%lld\n", 0, LLONG_MIN, 10000llu);
	loop_llong(f, "%lld\n", LLONG_MAX, 0, 10000llu);
	loop_llong(f, "%lld\n", LLONG_MIN, 0, 10000llu);

	loop_uint(f, "%u\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%u\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%lu\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%lu\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%llu\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%llu\n", ULLONG_MAX, 0, 10000llu);

	loop_uint(f, "%x\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%x\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%lx\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%lx\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%llx\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%llx\n", ULLONG_MAX, 0, 10000llu);

	loop_uint(f, "%X\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%X\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%lX\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%lX\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%llX\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%llX\n", ULLONG_MAX, 0, 10000llu);

	loop_uint(f, "%o\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%o\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%lo\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%lo\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%llo\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%llo\n", ULLONG_MAX, 0, 10000llu);

	//WIDTH
	loop_int(f, "%100d\n", 0, INT_MAX, 10000llu);
	loop_int(f, "%100d\n", 0, INT_MIN, 10000llu);
	loop_int(f, "%100d\n", INT_MAX, 0, 10000llu);
	loop_int(f, "%100d\n", INT_MIN, 0, 10000llu);

	loop_long(f, "%100ld\n", 0, LONG_MAX, 10000llu);
	loop_long(f, "%100ld\n", 0, LONG_MIN, 10000llu);
	loop_long(f, "%100ld\n", LONG_MAX, 0, 10000llu);
	loop_long(f, "%100ld\n", LONG_MIN, 0, 10000llu);

	loop_llong(f, "%100lld\n", 0, LLONG_MAX, 10000llu);
	loop_llong(f, "%100lld\n", 0, LLONG_MIN, 10000llu);
	loop_llong(f, "%100lld\n", LLONG_MAX, 0, 10000llu);
	loop_llong(f, "%100lld\n", LLONG_MIN, 0, 10000llu);

	loop_uint(f, "%100u\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%100u\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%100lu\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%100lu\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%100llu\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%100llu\n", ULLONG_MAX, 0, 10000llu);

	loop_uint(f, "%100x\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%100x\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%100lx\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%100lx\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%100llx\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%100llx\n", ULLONG_MAX, 0, 10000llu);

	loop_uint(f, "%100X\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%100X\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%100lX\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%100lX\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%100llX\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%100llX\n", ULLONG_MAX, 0, 10000llu);

	loop_uint(f, "%100o\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%100o\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%100lo\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%100lo\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%100llo\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%100llo\n", ULLONG_MAX, 0, 10000llu);

	//PRECISION
	loop_int(f, "%.50d\n", 0, INT_MAX, 10000llu);
	loop_int(f, "%.50d\n", 0, INT_MIN, 10000llu);
	loop_int(f, "%.50d\n", INT_MAX, 0, 10000llu);
	loop_int(f, "%.50d\n", INT_MIN, 0, 10000llu);

	loop_long(f, "%.50ld\n", 0, LONG_MAX, 10000llu);
	loop_long(f, "%.50ld\n", 0, LONG_MIN, 10000llu);
	loop_long(f, "%.50ld\n", LONG_MAX, 0, 10000llu);
	loop_long(f, "%.50ld\n", LONG_MIN, 0, 10000llu);

	loop_llong(f, "%.50lld\n", 0, LLONG_MAX, 10000llu);
	loop_llong(f, "%.50lld\n", 0, LLONG_MIN, 10000llu);
	loop_llong(f, "%.50lld\n", LLONG_MAX, 0, 10000llu);
	loop_llong(f, "%.50lld\n", LLONG_MIN, 0, 10000llu);

	loop_uint(f, "%.50u\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%.50u\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%.50lu\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%.50lu\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%.50llu\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%.50llu\n", ULLONG_MAX, 0, 10000llu);

	loop_uint(f, "%.50x\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%.50x\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%.50lx\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%.50lx\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%.50llx\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%.50llx\n", ULLONG_MAX, 0, 10000llu);

	loop_uint(f, "%.50X\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%.50X\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%.50lX\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%.50lX\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%.50llX\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%.50llX\n", ULLONG_MAX, 0, 10000llu);

	loop_uint(f, "%.50o\n", 0, UINT_MAX, 10000llu);
	loop_uint(f, "%.50o\n", UINT_MAX, 0, 10000llu);

	loop_ulong(f, "%.50lo\n", 0, ULONG_MAX, 10000llu);
	loop_ulong(f, "%.50lo\n", ULONG_MAX, 0, 10000llu);

	loop_ullong(f, "%.50llo\n", 0, ULLONG_MAX, 10000llu);
	loop_ullong(f, "%.50llo\n", ULLONG_MAX, 0, 10000llu);

	//MISC

		//with signed int, positive
	loop_int(f, "%+d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%+100d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%+100.50d\n", 0, INT_MAX, 1000llu);

	loop_int(f, "% d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "% 100d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "% 100.50d\n", 0, INT_MAX, 1000llu);

	loop_int(f, "%-d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%-100d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%-100.50d\n", 0, INT_MAX, 1000llu);

	loop_int(f, "%#x\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%#100x\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%#100.50x\n", 0, INT_MAX, 1000llu);

	loop_int(f, "%#X\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%#100X\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%#100.50X\n", 0, INT_MAX, 1000llu);

	loop_int(f, "%#o\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%#100o\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%#100.50o\n", 0, INT_MAX, 1000llu);

		//with signed int, negative
	loop_int(f, "%+d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "%+100d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "%+100.50d\n", 0, INT_MIN, 1000llu);

	loop_int(f, "% d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "% 100d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "% 100.50d\n", 0, INT_MIN, 1000llu);

	loop_int(f, "%-d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "%-100d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "%-100.50d\n", 0, INT_MIN, 1000llu);

		//with unsigned long
	loop_ullong(f, "%+lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%+100lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%+100.50lld\n", ULLONG_MAX, 0, 1000llu);

	loop_ullong(f, "% lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "% 100lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "% 100.50lld\n", ULLONG_MAX, 0, 1000llu);

	loop_ullong(f, "%-lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%-100lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%-100.50lld\n", ULLONG_MAX, 0, 1000llu);

	loop_ullong(f, "%#lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%#100lld\n", ULLONG_MAX, 0, 10llu);
	loop_ullong(f, "%#100.50lld\n", ULLONG_MAX, 0, 1000llu);

	loop_ullong(f, "%#llx\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%#100llx\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%#100.50llx\n", ULLONG_MAX, 0, 1000llu);

	loop_ullong(f, "%#llX\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%#100llX\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%#100.50llX\n", ULLONG_MAX, 0, 1000llu);
	
	loop_ullong(f, "%#llo\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%#100llo\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%#100.50llo\n", ULLONG_MAX, 0, 1000llu);

		//with unsigned long from 0
	loop_ullong(f, "%+lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%+100lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%+100.50lld\n", 0, ULLONG_MAX, 1000llu);

	loop_ullong(f, "% lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "% 100lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "% 100.50lld\n", 0, ULLONG_MAX, 1000llu);

	loop_ullong(f, "%-lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%-100lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%-100.50lld\n", 0, ULLONG_MAX, 1000llu);

	loop_ullong(f, "%#lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%#100lld\n", 0, ULLONG_MAX, 10llu);
	loop_ullong(f, "%#100.50lld\n", 0, ULLONG_MAX, 1000llu);

	loop_ullong(f, "%#llx\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%#100llx\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%#100.50llx\n", 0, ULLONG_MAX, 1000llu);

	loop_ullong(f, "%#llX\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%#100llX\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%#100.50llX\n", 0, ULLONG_MAX, 1000llu);
	
	loop_ullong(f, "%#llo\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%#100llo\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%#100.50llo\n", 0, ULLONG_MAX, 1000llu);

		//with signed long, positive
	loop_llong(f, "%+lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "%+100lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "%+100.50lld\n", LLONG_MAX, 0, 1000llu);

	loop_llong(f, "% lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "% 100lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "% 100.50lld\n", LLONG_MAX, 0, 1000llu);

	loop_llong(f, "%-lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "%-100lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "%-100.50lld\n", LLONG_MAX, 0, 1000llu);

		//with signelld long, negative
	loop_llong(f, "%+lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "%+100lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "%+100.50lld\n", 0, LLONG_MIN, 1000llu);

	loop_llong(f, "% lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "% 100lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "% 100.50lld\n", 0, LLONG_MIN, 1000llu);

	loop_llong(f, "%-lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "%-100lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "%-100.50lld\n", 0, LLONG_MIN, 1000llu);

	//All the previous tests but with '0' flag

		//with signed int, positive
	loop_int(f, "%0+d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0+100d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0+100.50d\n", 0, INT_MAX, 1000llu);

	loop_int(f, "%0 d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0 100d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0 100.50d\n", 0, INT_MAX, 1000llu);

	loop_int(f, "%0-d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0-100d\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0-100.50d\n", 0, INT_MAX, 1000llu);

	loop_int(f, "%0#x\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0#100x\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0#100.50x\n", 0, INT_MAX, 1000llu);

	loop_int(f, "%0#X\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0#100X\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0#100.50X\n", 0, INT_MAX, 1000llu);

	loop_int(f, "%0#o\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0#100o\n", 0, INT_MAX, 1000llu);
	loop_int(f, "%0#100.50o\n", 0, INT_MAX, 1000llu);

		//with signed int, negative
	loop_int(f, "%0+d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "%0+100d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "%0+100.50d\n", 0, INT_MIN, 1000llu);

	loop_int(f, "%0 d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "%0 100d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "%0 100.50d\n", 0, INT_MIN, 1000llu);

	loop_int(f, "%0-d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "%0-100d\n", 0, INT_MIN, 1000llu);
	loop_int(f, "%0-100.50d\n", 0, INT_MIN, 1000llu);

		//with unsigned long
	loop_ullong(f, "%0+lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0+100lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0+100.50lld\n", ULLONG_MAX, 0, 1000llu);

	loop_ullong(f, "%0 lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0 100lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0 100.50lld\n", ULLONG_MAX, 0, 1000llu);

	loop_ullong(f, "%0-lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0-100lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0-100.50lld\n", ULLONG_MAX, 0, 1000llu);

	loop_ullong(f, "%0#lld\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0#100lld\n", ULLONG_MAX, 0, 10llu);
	loop_ullong(f, "%0#100.50lld\n", ULLONG_MAX, 0, 1000llu);

	loop_ullong(f, "%0#llx\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0#100llx\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0#100.50llx\n", ULLONG_MAX, 0, 1000llu);

	loop_ullong(f, "%0#llX\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0#100llX\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0#100.50llX\n", ULLONG_MAX, 0, 1000llu);
	
	loop_ullong(f, "%0#llo\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0#100llo\n", ULLONG_MAX, 0, 1000llu);
	loop_ullong(f, "%0#100.50llo\n", ULLONG_MAX, 0, 1000llu);

		//with unsigned long from 0
	loop_ullong(f, "%0+lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0+100lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0+100.50lld\n", 0, ULLONG_MAX, 1000llu);

	loop_ullong(f, "%0 lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0 100lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0 100.50lld\n", 0, ULLONG_MAX, 1000llu);

	loop_ullong(f, "%0-lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0-100lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0-100.50lld\n", 0, ULLONG_MAX, 1000llu);

	loop_ullong(f, "%0#lld\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0#100lld\n", 0, ULLONG_MAX, 10llu);
	loop_ullong(f, "%0#100.50lld\n", 0, ULLONG_MAX, 1000llu);

	loop_ullong(f, "%0#llx\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0#100llx\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0#100.50llx\n", 0, ULLONG_MAX, 1000llu);

	loop_ullong(f, "%0#llX\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0#100llX\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0#100.50llX\n", 0, ULLONG_MAX, 1000llu);
	
	loop_ullong(f, "%0#llo\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0#100llo\n", 0, ULLONG_MAX, 1000llu);
	loop_ullong(f, "%0#100.50llo\n", 0, ULLONG_MAX, 1000llu);

		//with signed long, positive
	loop_llong(f, "%0+lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "%0+100lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "%0+100.50lld\n", LLONG_MAX, 0, 1000llu);

	loop_llong(f, "%0 lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "%0 100lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "%0 100.50lld\n", LLONG_MAX, 0, 1000llu);

	loop_llong(f, "%0-lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "%0-100lld\n", LLONG_MAX, 0, 1000llu);
	loop_llong(f, "%0-100.50lld\n", LLONG_MAX, 0, 1000llu);

		//with signelld long, negative
	loop_llong(f, "%0+lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "%0+100lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "%0+100.50lld\n", 0, LLONG_MIN, 1000llu);

	loop_llong(f, "%0 lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "%0 100lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "%0 100.50lld\n", 0, LLONG_MIN, 1000llu);

	loop_llong(f, "%0-lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "%0-100lld\n", 0, LLONG_MIN, 1000llu);
	loop_llong(f, "%0-100.50lld\n", 0, LLONG_MIN, 1000llu);

		//pointers
	f("%p\n", NULL);

		//'zero' special cases

	f("%+d\n", 0);
	f("%+10d\n", 0);
	f("%+.0d\n", 0);
	f("%+10.0d\n", 0);
	f("%+010.0d\n", 0);

	f("%+d\n", 1);
	f("%+10d\n", 1);
	f("%+.0d\n", 1);
	f("%+10.0d\n", 1);

	f("%010.0d\n", 0);
	f("%010.0x\n", 0);
	f("%010.0X\n", 0);
	f("%010.0o\n", 0);

	f("%#010.0d\n", 0);
	f("%#010.0x\n", 0);
	f("%#010.0X\n", 0);
	f("%#010.0o\n", 0);

	f("%o\n", 123);
	f("%#o\n", 123);
	f("%.10o\n", 123);
	f("%#.10o\n", 123);
	f("%.2o\n", 123);
	f("%#.2o\n", 123);
	f("%.0o\n", 123);
	f("%#.0o\n", 123);
	f("%#010o\n", 123);
	f("%#010.2o\n", 123);
	f("%o\n", 0);
	f("%#o\n", 0);
	f("%#o\n", 1);
	f("%.10o\n", 0);
	f("%#.10o\n", 0);
	f("%.0o\n", 0);
	f("%#.0o\n", 0);
	f("%o\n", 0);
	f("%#o\n", 0);
	f("%010o\n", 0);
	f("%#010o\n", 0);
	f("%10o\n", 0);
	f("%#10o\n", 0);
	f("---------\n");

	f("%x\n", 123);
	f("%#x\n", 123);
	f("%.10x\n", 123);
	f("%#.10x\n", 123);
	f("%.2x\n", 123);
	f("%#.2x\n", 123);
	f("%.0x\n", 123);
	f("%#.0x\n", 123);
	f("%x\n", 0);
	f("%#x\n", 0);
	f("%.10x\n", 0);
	f("%#.10x\n", 0);
	f("%.0x\n", 0);
	f("%#.0x\n", 0);
	f("%x\n", 0);
	f("%#x\n", 0);
	f("%010x\n", 0);
	f("%#010x\n", 0);
	f("%10x\n", 0);
	f("%#10x\n", 0);
	f("---------\n");

	f("%X\n", 123);
	f("%#X\n", 123);
	f("%.10X\n", 123);
	f("%#.10X\n", 123);
	f("%.2X\n", 123);
	f("%#.2X\n", 123);
	f("%.0X\n", 123);
	f("%#.0X\n", 123);
	f("%X\n", 0);
	f("%#X\n", 0);
	f("%.10X\n", 0);
	f("%#.10X\n", 0);
	f("%.0X\n", 0);
	f("%#.0X\n", 0);
	f("%X\n", 0);
	f("%#X\n", 0);
	f("%010X\n", 0);
	f("%#010X\n", 0);
	f("%10X\n", 0);
	f("%#10X\n", 0);
	f("---------\n");

	f("%.d\n", 0);
	f("%.x\n", 0);
	f("%.X\n", 0);
	f("%.o\n", 0);
	f("%#.d\n", 0);
	f("%#.x\n", 0);
	f("%#.X\n", 0);
	f("%#.o\n", 0);
	
	f("%.1d\n", 0);
	f("%.1x\n", 0);
	f("%.1X\n", 0);
	f("%.1o\n", 0);
	f("%#.1d\n", 0);
	f("%#.1x\n", 0);
	f("%#.1X\n", 0);
	f("%#.1o\n", 0);
	f("---------\n");

	f("%f\n", 123.0);
	f("%#f\n", 123.0);
	f("%.10f\n", 123.0);
	f("%#.10f\n", 123.0);
	f("%.2f\n", 123.0);
	f("%#.2f\n", 123.0);
	f("%.0f\n", 123.0);
	f("%#.0f\n", 123.0);
	f("%f\n", 0.0);
	f("%#f\n", 0.0);
	f("%.10f\n", 0.0);
	f("%#.10f\n", 0.0);
	f("%.0f\n", 0.0);
	f("%#.0f\n", 0.0);
	f("%f\n", 0.0);
	f("%#f\n", 0.0);
	f("%010f\n", 0.0);
	f("%#010f\n", 0.0);
	f("%10f\n", 0.0);
	f("%#10f\n", 0.0);
	f("---------\n");

	f("%.f\n", 0.0);
	f("%.f\n", 0.0);
	f("%.f\n", 0.0);
	f("%.f\n", 0.0);
	f("%#.f\n", 0.0);
	f("%#.f\n", 0.0);
	f("%#.f\n", 0.0);
	f("%#.f\n", 0.0);
	
	f("%.1f\n", 0.0);
	f("%.1f\n", 0.0);
	f("%.1f\n", 0.0);
	f("%.1f\n", 0.0);
	f("%#.1f\n", 0.0);
	f("%#.1f\n", 0.0);
	f("%#.1f\n", 0.0);
	f("%#.1f\n", 0.0);

	//precision additional tests
	f("%0100.3d\n", 123456);
	f("%0100.3o\n", 123456);
	f("%0100.3x\n", 123456);
	f("%0100.3X\n", 123456);
	f("%0100.3u\n", 123456);
	f("%#0100.3d\n", 123456);
	f("%#0100.3o\n", 123456);
	f("%#0100.3x\n", 123456);
	f("%#0100.3X\n", 123456);
	f("%#0100.3u\n", 123456);
	f("%#0100.3d\n", 0);
	f("%#0100.3o\n", 0);
	f("%#0100.3x\n", 0);
	f("%#0100.3X\n", 0);
	f("%#0100.3u\n", 0);
}
