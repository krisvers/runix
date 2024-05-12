#include <parallel.h>
#include <x86/common.h>

#define PARALLEL_STATUS_PORT 0x379
#define PARALLEL_OUT_PORT 0x378
#define PARALLEL_SIGNAL_PORT 0x37A

#define PARALLEL_BUSY_BIT 0x80
#define PARALLEL_ACK_BIT 0x40

#define PARALLEL_STROBE 0x01

#define E9_PORT 0xE9

void parallel_write(char c) {
	outb(E9_PORT, c);

	/* wait until not busy */
	u8 in = inb(PARALLEL_STATUS_PORT);
	while (!(in & PARALLEL_BUSY_BIT)) {
		in = inb(PARALLEL_STATUS_PORT);
	}

	/* write character */
	outb(PARALLEL_OUT_PORT, c);

	/* signal strobe */
	outb(PARALLEL_SIGNAL_PORT, inb(PARALLEL_SIGNAL_PORT) | PARALLEL_STROBE);

	/* wait until acknowledged */
	in = inb(PARALLEL_STATUS_PORT);
	while (!(in & PARALLEL_ACK_BIT)) {
		in = inb(PARALLEL_STATUS_PORT);
	}

	/* unsignal strobe */
	outb(PARALLEL_SIGNAL_PORT, inb(PARALLEL_SIGNAL_PORT) & ~PARALLEL_STROBE);

	/* wait until acknowledged */
	in = inb(PARALLEL_STATUS_PORT);
	while (!(in & PARALLEL_ACK_BIT)) {
		in = inb(PARALLEL_STATUS_PORT);
	}
}
