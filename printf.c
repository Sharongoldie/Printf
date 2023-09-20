#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces custom printf function
 * @format: format string containing the characters and specifiers
 * Description: This function call the get_print() function that
 * will determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: Number of characters printed (excluding NULL byte used to end out
 * or -1 if error occurs
 */

int _printf(const char *format, ...) {
	va_list args;
	va_start(args, format);

	int count = 0;	/* Count of characters printed */

	while (*format) {
	if (*format == '%') {
	format++;	/* Move past the '%' charcter */
	char spec = *format;

	if (spec == '\0') {
		break; // In case of '%' at the end of the format string
	}
	
	if (spec == 'c') {
		/* Handle %c for characters in ASCII */
		char ch = va_arg(args, int); /* promote char to int in varargs */
		putchar(ch);
		count++;
		} else if (spec == 's') {
		/* Handle %s (string) */
		char *str = va_arg(args, char *);
		while (*str) {
		putchar(*str);
		str++;
		count++;
		}

		} else if (spec == '%') {
		/* Handle the percentage (%%) character */
		putchar('%');
		count++;
		}

	}
	else {
	/* print any character that's valid */
	putchar(*format);
	count++;
	}

	format++;
	}

	va_end(args);
	return count;
}

int main()

{
	int num_chars = _printf("Hello, %s! This is a %c example: %%%c\n", "world", 'C', 'A');
	printf("\nTotal characters printed: %d\n", num_chars);
	return 0;
}
