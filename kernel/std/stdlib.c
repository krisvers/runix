#include <std/stdlib.h>

__attribute__((__noreturn__))
void abort(void) {
	// TODO: Add proper kernel panic.
	printf("kernel: panic: abort()\n");
        asm volatile("hlt");

	while (1);
	
	__builtin_unreachable();
}
