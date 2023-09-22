#include "main.h"

int _putchar(char c);

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    int printed_chars = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            _putchar(*format);
            printed_chars++;
        }
        else
        {
            format++;
            if (*format == '\0')
                return (-1);

            if (*format == '%')
            {
                _putchar('%');
                printed_chars++;
            }
            else if (*format == 'c')
            {
                char c = va_arg(args, int);
                _putchar(c);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    _putchar(*str);
                    printed_chars++;
                    str++;
                }
            }
            else
            {
                _putchar('%');
                _putchar(*format);
                printed_chars += 2;
            }
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}
