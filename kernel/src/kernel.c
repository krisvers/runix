#include <tty.h>
#include <print.h>
#include <boot.h>
#include <mem.h>
#include <x86/common.h>
#include <x86/idt.h>
#include <x86/isr.h>
#include <x86/irq.h>

extern char _BSS_START;
extern char _BSS_END;

bootinfo_t* bootinfo;

void syscall(x86_registers_t* regs) {
	if (regs->eax == 0) {
		putc(regs->ebx, regs->ecx);
	}
}

extern void task(void);

void __attribute__((section(".entry"))) ckernel(void) {
	memset(&_BSS_START, 0, &_BSS_END - &_BSS_START);

	tty_setup((char*) 0xB8000, 80, 25);
	puts("zaza\n", 0x02);

	int_disable();
	nmi_disable();

	idt_init();
	isr_init();
	irq_init();

	nmi_enable();
	int_enable();

	isr_register(0x80, syscall);

	task();

	while (1) {}
}
