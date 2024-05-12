#include <print.h>
#include <tty.h>

void putc(char c, u8 color) {
	tty_putc(c, color);
}

void puts(char* string, u8 color) {
	while (*string != '\0') {
		tty_putc(*string, color);
		++string;
	}
}

void putslen(char* string, u32 length, u8 color) {
	while (length--) {
		tty_putc(*string, color);
		++string;
	}
}

void putn(u32 number, u32 radix, u8 color) {
	const char basechars[16] = "0123456789abcdef";
	if (radix > 16) {
		radix = 16;
	} else if (radix < 2) {
		radix = 2;
	}

	if (number == 0) {
		tty_putc('0', color);
		return;
	}

	char buffer[64];
	u32 index = 0;

	do {
		buffer[index++] = basechars[number % radix];
		number /= radix;
		if (index >= 64) {
			break;
		}
	} while (number > 0);

	while (index-- > 0) {
		tty_putc(buffer[index], color);
	}
}
