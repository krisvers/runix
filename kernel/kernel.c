#include "terminal/terminal.h"

void ckernel() {
	terminal_init(80, 25, (char * const) 0xB8000, 2);
	terminal_putc(0, 0, 'k', 0x02);

	while (1);
}
