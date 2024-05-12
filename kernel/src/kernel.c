#include <tty.h>
#include <print.h>
#include <boot.h>
#include <mem.h>
#include <x86/common.h>
#include <x86/idt.h>
#include <x86/isr.h>

extern char _BSS_START;
extern char _BSS_END;

bootinfo_t* bootinfo;

void __attribute__((section(".entry"))) ckernel(void) {
	memset(&_BSS_START, 0, &_BSS_END - &_BSS_START);

	tty_setup((char*) 0xB8000, 80, 25);
	puts("zaza\n", 0x02);

	int_disable();
	nmi_disable();

	idt_init();
	isr_init();

	nmi_enable();
	int_enable();

	while (1) {}
}
