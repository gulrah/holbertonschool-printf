#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'c')
        {
            char c = va_arg(args, int);
            putchar(c);
            format += 2;
            count++;
        }
        else if (*format == '%' && *(format + 1) == 's')
        {
            char *str = va_arg(args, char *);
            printf("%s", str);
            format += 2;
            count += strlen(str);
        }
        else
        {
            putchar(*format);
            format++;
            count++;
        }
    }

    va_end(args);

    return count;
}
