#include "main.h"

/**
 * print_c - function that print char
 * @c: input char
 * Return: always 1
 */
int print_c(va_list c)
{
	char character = (char) va_arg(c, int);

	_putchar(character);
	return (1);
}
