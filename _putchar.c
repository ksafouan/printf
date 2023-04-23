#include "main.h"
#include <unistd.h>

/**
 * _putchar - write the character in c 
 * @c: input string
 * Return: @c
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
