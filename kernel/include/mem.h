#ifndef KROS_MEM_H
#define KROS_MEM_H

#include <types.h>

void memcpy(void* dst, void* src, usize size);
void memmov(void* dst, void* src, usize size);
void memset(void* dst, u8 value, usize size);

void strcpy(char* dst, char* src, usize size);
usize strcmp(char* stra, char* strb);
usize strncmp(char* first, char* second, usize length);

#endif
