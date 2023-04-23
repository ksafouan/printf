#include "main"
#include <stdlib.h>

/**
 * print_d - function print d
 * @i: integer to print
 * Return: number of print digits
 */

int print_d(va_list i)
{
	int a[10];
	int j = 1, m = 1000000000, n, sum = 0, count = 0;

	n = va_arg(i, int);
	if (n < 0)
	{

		n *= -1;
		_putchar('-');
		count++;
	}
	a[0] = n / m;

	for (; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}

	for (j = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
		{
			_putchar('0' + a[j]);
			count++;
		}
	}
	return (count);
}
