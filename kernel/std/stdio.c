#include <std/stdio.h>

static char hex_chars[16] = "0123456789ABCDEF";
static enum vga_color color = WHITE;

void putcolor(enum vga_color col) {
    color = col;
}

int puts(const char * string) {
	return printf("%s\n", string);
}

int putc(int ic) {
	char c = (char) ic;
	if (c == '\n') {
        tty_linefeed();
	} else if (c == '\t') {
        tty_tab();
    } else if (c == '\b') {
        tty_backspace();
	} else {
		tty_putc(c, color);
	}

	// TODO: Implement stdio and the write system call.
	return ic;
}

static bool print(const char * data, size_t length) {
	const unsigned char * bytes = (const unsigned char *) data;
	for (size_t i = 0; i < length; i++)
		if (putc(bytes[i]) == EOF) {
			return false;
		}
	return true;
}
 
int printf(const char * restrict format, ...) {
	va_list parameters;
	va_start(parameters, format);
 
	int written = 0;
 
	while (*format != '\0') {
		size_t maxrem = INT_MAX - written;
 
		if (format[0] != '%' || format[1] == '%') {
			if (format[0] == '%') {
				format++;
			}
			size_t amount = 1;
			while (format[amount] && format[amount] != '%') {
				amount++;
			}
			if (maxrem < amount) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, amount)) {
				return -1;
			}
			format += amount;
			written += amount;
			continue;
		}

		const char * format_begun_at = format++;
 
		if (*format == 'c') {
			format++;
			char c = (char) va_arg(parameters, int /* char promotes to int */);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(&c, sizeof(c))) {
				return -1;
			}
			written++;
		} else if (*format == 's') {
			format++;
			const char * str = va_arg(parameters, const char *);
			size_t len = strlen(str);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len)) {
				return -1;
			}
			written += len;
		} else if (*format == 'd' || *format == 'i') {
			format++;
			int num = va_arg(parameters, int);
			char buffer[32];
			int pos = 0;

			do {
				unsigned long long rem = num % 10;
				num /= 10;
				buffer[pos++] = hex_chars[rem];
			} while (num > 0);

			while (--pos >= 0) {
				putc(buffer[pos]);
			}
        } else if (*format == 'x') {
            putc('0');
            putc('x');
            format++;
            int num = va_arg(parameters, int);
            char buffer[32];
            int pos = 0;

            do {
                unsigned long long rem = num % 16;
                num /= 16;
                buffer[pos++] = hex_chars[rem];
            } while (num > 0);

            while (--pos >= 0) {
                putc(buffer[pos]);
            }
        } else if (*format == 'b') {
            putc('0');
            putc('b');
            format++;
            int num = va_arg(parameters, int);
            char buffer[32];
            int pos = 0;

            do {
                unsigned long long rem = num % 2;
                num /= 2;
                buffer[pos++] = hex_chars[rem];
            } while (num > 0);

            while (--pos >= 0) {
                putc(buffer[pos]);
            }
		} else {
			format = format_begun_at;
			size_t len = strlen(format);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, len)) {
				return -1;
			}
			written += len;
			format += len;
		}
	}
 
	va_end(parameters);
	return written;
}
