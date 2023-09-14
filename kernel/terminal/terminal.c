#include "terminal.h"

static unsigned int terminal_width = 0;
static unsigned int terminal_height = 0;
static char * terminal_video_memory;
static unsigned int terminal_bpc = 0;

void terminal_init(unsigned int width, unsigned int height, char * const video_memory, unsigned int bpc) {
	terminal_width = width;
	terminal_height = height;
	terminal_video_memory = video_memory;
	terminal_bpc = bpc;
}

void terminal_putc(unsigned int x, unsigned int y, char c, unsigned char color) {
	terminal_video_memory[terminal_bpc * (x + (y * terminal_width))] = c;
	terminal_video_memory[1 + terminal_bpc * (x + (y * terminal_width))] = color;
}
