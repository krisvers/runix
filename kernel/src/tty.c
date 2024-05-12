#include <tty.h>
#include <parallel.h>

static char* vmem_address;
static unsigned int tty_width = 0;
static unsigned int tty_height = 0;
static unsigned int tty_x = 0;
static unsigned int tty_y = 0;

void tty_putc(char c, unsigned char color) {
	if (c == '\n') {
		parallel_write('\r');
	}

	parallel_write(c);
	if (c >= '!' && c <= '~') {
		vmem_address[(tty_x + tty_y * tty_width) * 2] = c;
		vmem_address[(tty_x + tty_y * tty_width) * 2 + 1] = color;
	} else if (c == '\n') {
		++tty_y;
		tty_x = 0;
		if (tty_y >= tty_height) {
			tty_y = 0;
			/* scroll */
		}
		return;
	} else if (c == '\b') {
		--tty_x;
		vmem_address[(tty_x + tty_y * tty_width) * 2] = ' ';
		vmem_address[(tty_x + tty_y * tty_width) * 2 + 1] = color;
		return;
	}

	++tty_x;
	if (tty_x >= tty_width) {
		tty_x = 0;
		++tty_y;
		if (tty_y >= tty_height) {
			tty_y = 0;
			/* scroll */
		}
	}
}

void tty_setup(char* address, unsigned int width, unsigned int height) {
	vmem_address = address;
	tty_width = width;
	tty_height = height;
}
