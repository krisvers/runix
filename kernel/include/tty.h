#ifndef KROS_TTY_H
#define KROS_TTY_H

#include <types.h>

void tty_putc(char c, unsigned char color);
void tty_setup(char* address, u32 width, u32 height);

#endif
