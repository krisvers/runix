extern char _BSS_START;
extern char _BSS_END;

#include <std/stdio.h>

void main();

void __attribute__((section(".entry"))) _kernelentry() {
	for (char * addr = &_BSS_START; addr < &_BSS_END; addr++) {
		* addr = 0;
	}

	main();

	while(1);
}
