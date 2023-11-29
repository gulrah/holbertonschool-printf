#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include "main.h"
<<<<<<< HEAD

=======
>>>>>>> 5e9305a97f9759843197770166086a5c6b25f8b5
int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    va_start(args, format);
<<<<<<< HEAD

=======
>>>>>>> 5e9305a97f9759843197770166086a5c6b25f8b5
    while (format && *format) {
        if (*format == '%' && *(format + 1)) {
            format++;
            switch (*format) {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    count += _puts(va_arg(args, char *));
                    break;
                case 'd':
                    count += _print_number(va_arg(args, int));
                    break;
<<<<<<< HEAD
		case 'i':
                    count += _print_number(va_arg(args, int));
                    break;
		case 'u':
=======
                case 'i':
                    count += _print_number(va_arg(args, int));
                    break;
                case 'u':
>>>>>>> 5e9305a97f9759843197770166086a5c6b25f8b5
                    count += _print_unsigned(va_arg(args, unsigned int));
                    break;
                case 'p':
                    count += _print_pointer(va_arg(args, void *));
                    break;
<<<<<<< HEAD
		case 'o':
                    count += _print_octal(va_arg(args, unsigned int));
                    break;
		case 'x':
=======
                case 'o':
                    count += _print_octal(va_arg(args, unsigned int));
                    break;
                case 'x':
>>>>>>> 5e9305a97f9759843197770166086a5c6b25f8b5
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
<<<<<<< HEAD

int _putchar(char c) {
    return write(1, &c, 1);
}

=======
int _putchar(char c) {
    return write(1, &c, 1);
}
>>>>>>> 5e9305a97f9759843197770166086a5c6b25f8b5
int _puts(char *str) {
    int count = 0;
    while (str && *str) {
        count += _putchar(*str);
        str++;
    }
    return count;
}
<<<<<<< HEAD

=======
>>>>>>> 5e9305a97f9759843197770166086a5c6b25f8b5
int _print_number(int n) {
    if (n < 0) {
        _putchar('-');
        n = -n;
    }
<<<<<<< HEAD

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

=======
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
>>>>>>> 5e9305a97f9759843197770166086a5c6b25f8b5
    /* Print each nibble without leading zeros */
    for (i = nibbles - 1; i >= 0; i--) {
        int digit = (addr >> (i * 4)) & 0xF;
        if (digit > 0 || i == 0) {
            count += _putchar("0123456789abcdef"[digit]);
        }
    }
<<<<<<< HEAD

    return count;
}

=======
    return count;
}
>>>>>>> 5e9305a97f9759843197770166086a5c6b25f8b5
int _print_unsigned(unsigned int n) {
    if (n / 10 != 0) {
        _print_unsigned(n / 10);
    }
<<<<<<< HEAD

    return _putchar((n % 10) + '0');
}

=======
    return _putchar((n % 10) + '0');
}
>>>>>>> 5e9305a97f9759843197770166086a5c6b25f8b5
int _print_octal(unsigned int n) {
    if (n / 8 != 0) {
        _print_octal(n / 8);
    }
<<<<<<< HEAD

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
=======
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







>>>>>>> 5e9305a97f9759843197770166086a5c6b25f8b5
