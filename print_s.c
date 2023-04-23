#include "main.h"
#include <unistd.h>

/**
 * print_s - function that prints a string
 * @s: input string
 * Return: always 1
 */
int print_s(va_list s)
{
	char *str = va_arg(s, char*);
	int i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
		_putchar(str[i++]);

	return (i);
}
