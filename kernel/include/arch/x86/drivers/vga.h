#pragma once
#include <std/types.h>
#include <std/string.h>

enum vga_color {
    BLACK = 0x00,
    GREY = 0x08,
    LIGHT_GREY = 0x07,
    WHITE = 0x0F,
    RED = 0x0C,
    YELLOW = 0x0E,
    ORANGE = 0x06,
    GREEN = 0x0A,
    CYAN = 0x0B,
    BLUE = 0x09,
    PURPLE = 0x05,
    PINK = 0x0D,
};

void vga_putc(int x, int y, char c, enum vga_color fg_color, enum vga_color bg_color);
void vga_setbg(enum vga_color bg);
void vga_clear();
void vga_fill(enum vga_color color);
char vga_getc(int x, int y);
void vga_scroll();
