#include "main.h"
#include <stdarg.h>
#include <unistd.h> /* For write */

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    if (!format)
        return -1; /* Handle NULL format pointer */

    va_list args;
    int count = 0;
    const char *ptr = format;

    va_start(args, format);

    while (*ptr)
    {
        if (*ptr == '%' && *(ptr + 1) == 'c')
        {
            char c = va_arg(args, int);
            write(1, &c, 1);
            count++;
            ptr += 2; /* Skip '%c' */
        }
        else if (*ptr == '%' && *(ptr + 1) == 's')
        {
            char *str = va_arg(args, char*);
            if (str)
            {
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else
            {
                write(1, "(null)", 6);
                count += 6; /* Length of "(null)" */
            }
            ptr += 2; /* Skip '%s' */
        }
        else if (*ptr == '%' && *(ptr + 1) == '%')
        {
            write(1, "%", 1);
            count++;
            ptr += 2; /* Skip '%%' */
        }
        else
        {
            write(1, ptr, 1);
            count++;
            ptr++;
        }
    }

    va_end(args);
    return count;
}
