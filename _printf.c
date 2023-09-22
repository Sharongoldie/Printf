#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);

#endif /* MAIN_H */

#include "main.h"

/**
 * _putchar - Custom putchar function
 * @c: The character to print
 * Return: On success 1. On error -1 and errno set appropriately.
 */

int _putchar(char c)

{
	return (write(1, &c, 1));
}

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)

{

	va_list args;
	int count = 0;
	char *str;

	va_start(args, format);

	while (format && *format)
	  {

	  if (*format != '%')
	    {
	_putchar(*format);
	count++;
	}

else

{
	format++;
	switch (*format)
	  {

	case 'c':
		_putchar(va_arg(args, int));
		count++;
			break;

	case 's':
		str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
			while (*str)
			  {

			_putchar(*str);
			count++;
			str++;
			}
			break;

		case '%':
			_putchar('%');
			count++;
			break;

		default:
			_putchar('%');
			_putchar(*format);
			count += 2;
		}
	}

	format++;
	}

	va_end(args);

	return (count);
}
