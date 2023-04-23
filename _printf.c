#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * check_format - function to check the format of input
 * @format: input const char
 * Return: pointer
 */
int (*check_format(const char *format))(va_list)
{
	int i = 0;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_i},
		{NULL, NULL}

	};
	for (; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
			break;
	}

	return (p[i].f);
}

/**
 * _printf - function that produces output according to a format
 * @format: const char
 * @...: other parameters
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
			i++;
			continue;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				count++;
				i += 2;
				continue;
			}
			else
			{
				f = check_format(&format[i + 1]);
				if (f == NULL)
					return (-1);
				i += 2;
				count += f(ap);
				continue;
			}
		}
		i++;
	}

	va_end(ap);
	return (count);
}
