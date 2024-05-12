#ifndef KROS_PRINT_H
#define KROS_PRINT_H

#include <types.h>

void putc(char c, u8 color);
void puts(char* string, u8 color);
void putslen(char* string, u32 length, u8 color);
void putn(u32 number, u32 radix, u8 color);

#endif
