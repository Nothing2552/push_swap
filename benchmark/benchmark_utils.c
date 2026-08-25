#include "push_swap.h"

void	bench_putstr(char *str)
{
	int	length;

	if (!str)
		return ;
	length = 0;
	while (str[length])
		length++;
	write(2, str, length);
}

void	bench_putnbr(long number)
{
	char	digit;

	if (number >= 10)
		bench_putnbr(number / 10);
	digit = number % 10 + '0';
	write(2, &digit, 1);
}

void	bench_put_metric(char *name, long value)
{
	bench_putstr(name);
	bench_putnbr(value);
	write(2, "\n", 1);
}

void	benchmark_print_disorder(double disorder)
{
	long	scaled;
	long	integer;
	long	decimal;

	scaled = (long)(disorder * 10000.0 + 0.5);
	integer = scaled / 100;
	decimal = scaled % 100;
	bench_putstr("Disorder: ");
	bench_putnbr(integer);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	bench_putnbr(decimal);
	bench_putstr("%\n");
}