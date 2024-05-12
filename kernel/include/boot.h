#ifndef KROS_BOOT_H
#define KROS_BOOT_H

#include <types.h>

typedef struct bootgraphics_t {
	s32 textmode;
	void* address;
	u32 width;
	u32 height;
	u32 bpp;
} bootgraphics_t;

typedef struct bootinfo_t {
	bootgraphics_t graphics;
	char* signature;
} bootinfo_t;

#endif
