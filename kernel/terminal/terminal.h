#ifndef KRISVERS_KERNEL_TERMINAL_TERMINAL_H
#define KRISVERS_KERNEL_TERMINAL_TERMINAL_H

void terminal_init(unsigned int width, unsigned int height, char * const video_memory, unsigned int bpc);
void terminal_putc(unsigned int x, unsigned int y, char c, unsigned char color);

#endif
