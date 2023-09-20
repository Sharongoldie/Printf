#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/* Declaration of _putchar function */
int _putchar(char c);

/**
 * _printf - produces custom printf function
 * @format: format string containing the characters and specifiers
 *
 * Description: This function calls the get_print() function that
 * will determine which printing function to call depending on the conversion
 * specifiers contained in fmt.
 *
 * Return: Number of characters printed (excluding NULL byte used to end output)
 * or -1 if an error occurs
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0; /* Count of characters printed */

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            char spec = *format;

            if (spec == '\0')
            {
                break; /* In case of '%' at the end of the format string */
            }

            if (spec == 'c')
            {
                /* Handle %c for characters in ASCII */
                char ch = va_arg(args, int); /* Promote char to int in varargs */
                _putchar(ch);
                count++;
            }
            else if (spec == 's')
            {
                /* Handle %s (string) */
                char *str = va_arg(args, char *);
                while (*str)
                {
                    _putchar(*str);
                    str++;
                    count++;
                }
            }
            else if (spec == '%')
            {
                /* Handle the percentage (%%) character */
                _putchar('%');
                count++;
            }
        }
        else
        {
            /* Print any character that's valid */
            _putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int num_chars = _printf("Hello, %s! This is a %c example: %%%c\n", "world", 'C', 'A');
    printf("\nTotal characters printed: %d\n", num_chars);
    return 0;
}
