#include "main.h"
<<<<<<< HEAD
#include <stdarg.h>

/**
 * check_format - checks if there is a valid format specifier
 * @format: possible valid format specifier
 * Return: pointer to valid function or NULL
 */
int (*check_format(const char *format))(va_list)
{
	int i = 0;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
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
 * _printf - function for format printing
 * @format: list of arguments to printing
 * Return: Number of characters to printing
=======

/**
 * _printf - prints everything
 * @format: the format string
 * @...: other parameter
 * Return: number of bytes
>>>>>>> a42d3c0af5c228007b9c912d8b4105bfe4633ce8
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
<<<<<<< HEAD
	int (*f)(va_list);
	unsigned int i = 0, counter = 0;

	if (format == NULL)
		return (-1);
=======
	char *p, *start;
	params_t params = PARAMS_INIT;
>>>>>>> a42d3c0af5c228007b9c912d8b4105bfe4633ce8

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);
		if (*p != '%')
		{
<<<<<<< HEAD
			_putchar(format[i]);
			counter++;
			i++;
=======
			sum += _putchar(*p);
>>>>>>> a42d3c0af5c228007b9c912d8b4105bfe4633ce8
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
<<<<<<< HEAD
			if (format[i + 1] == '%')
			{
				_putchar('%');
				counter++;
				i += 2;
				continue;
			}
			else
			{
				f = check_format(&format[i + 1]);
				if (f == NULL)
					return (-1);
				i += 2;
				counter += f(ap);
				continue;
			}
=======
			p++;
>>>>>>> a42d3c0af5c228007b9c912d8b4105bfe4633ce8
		}
		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, params))
			p++;
		if (!get_specifier(p))
			sum += print_form_to(start, p, params.l_modifier
					|| params.hçmodifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &params);
	}
<<<<<<< HEAD
	va_end(ap);
	return (counter);
=======

	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
>>>>>>> a42d3c0af5c228007b9c912d8b4105bfe4633ce8
}
