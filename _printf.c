#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    if (format == NULL)
	    return -1;

    va_start(args, format);

    while (format && *format) {
        if (*format == '%' && *(format + 1)) {
            format++;
            switch (*format) {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's': {
                    char *str = va_arg(args, char *);
                    if (str == NULL) {
                        count += _puts("(null)");
                    } else {
                        count += _puts(str);
                    }
                    break;
                }
                case 'd':
                    count += _print_number(va_arg(args, int));
                    break;
                case 'p':
                    count += _print_pointer(va_arg(args, void *));
                    break;
                case 'u':
                    count += _print_unsigned(va_arg(args, unsigned int));
                    break;
                case 'o':
                    count += _print_octal(va_arg(args, unsigned int));
                    break;
                case 'x':
                    count += _print_hex(va_arg(args, unsigned int), 0);
                    break;
                case 'X':
                    count += _print_hex(va_arg(args, unsigned int), 1);
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                default:
                    count += _putchar('%') + _putchar(*format);
                    break;
            }
        } else {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);

    return count;
}

int _putchar(char c) {
    return write(1, &c, 1);
}
int _puts(char *str) {
    int count = 0;
    while (str && *str) {
        count += _putchar(*str);
        str++;
    }
    return count;
}
int _print_number(int n) {
    if (n < 0) {
        _putchar('-');
        n = -n;
    }
    if (n / 10 != 0) {
        _print_number(n / 10);
    }
    return _putchar((n % 10) + '0');
}
int _print_pointer(void *ptr) {
    int count = 0, i;
    uintptr_t addr = (uintptr_t)ptr;
    int nibbles = (sizeof(void *) * 2);
    count += _putchar('0') + _putchar('x');
    /* Print each nibble without leading zeros */
    for (i = nibbles - 1; i >= 0; i--) {
        int digit = (addr >> (i * 4)) & 0xF;
        if (digit > 0 || i == 0) {
            count += _putchar("0123456789abcdef"[digit]);
        }
    }
    return count;
}
int _print_unsigned(unsigned int n) {
    if (n / 10 != 0) {
        _print_unsigned(n / 10);
    }
    return _putchar((n % 10) + '0');
}
int _print_octal(unsigned int n) {
    if (n / 8 != 0) {
        _print_octal(n / 8);
    }
    return _putchar((n % 8) + '0');
}
int _print_hex(unsigned int n, int uppercase) {
    int digit = n % 16;
    char hexChar = (digit < 10) ? ('0' + digit) : (uppercase ? ('A' + digit - 10) : ('a' + digit - 10));
    if (n / 16 != 0) {
        _print_hex(n / 16, uppercase);
    }
    return _putchar(hexChar);
}
