#include <arch/x86/hal/gdt.h>
#include <arch/x86/hal/idt.h>
#include <arch/x86/hal/isr.h>
#include <arch/x86/hal/irq.h>
#include <arch/x86/hal/pic.h>
#include <arch/x86/hal/pit.h>
#include <arch/x86/drivers/cpubasics.h>
#include <std/stdio.h>
#include <std/stdlib.h>
#include <arch/x86/drivers/tty.h>
#include <arch/x86/drivers/vga.h>
#include <arch/x86/drivers/keyboard.h>
#include <std/stdbool.h>

static char * art = \
".      .              ,cc.\n"
"H ,dP  HdRH.  ,cOc,  A`  `\n"
"HDP`   H`  o  H   H   `*o.\n"
"H `Tb  H      `QoP`  ~c.d`    :)\n"
"\n";

void main() {
    putcolor(BLUE);
    printf("welcome to kros!\n");
    printf("%s", art);

	gdt_init();
	idt_init();
	isr_init();
	irq_init();
    pit_init();
    keyboard_init();
    printf("PCI: configuration: %x, number of devices: %x\n", *((char *) 0x501), *((char *) 0x500));

    putcolor(WHITE);
    printf("\n> ");

	while (1) {

	}
}