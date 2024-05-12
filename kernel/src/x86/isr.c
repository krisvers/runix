#include <x86/isr.h>
#include <print.h>
#include <def.h>

static char* const exceptions[] = {
	"Divide by zero exception",
	"Debug",
	"Non-maskable interrupt",
	"Breakpoint",
	"Overflow",
	"Bound Range Exceeded",
	"Invalid Opcode",
	"Device Not Available",
	"Double Fault",
	"Coprocessor Segment Overrun",
	"Invalid TSS",
	"Segment Not Present",
	"Stack Segment Fault",
	"General Protection Fault",
	"Page Fault",
	"",
	"x87 Floating-Point Exception",
	"Alignment Check",
	"Machine Check",
	"SIMD Floating-Point Exception",
	"Virtualization Exception",
	"Control Protection Exception",
	"",
	"",
	"",
	"",
	"",
	"",
	"Hypervisor Injection Exception",
	"VMM Communication Exception",
	"Security Exception",
	""
};

static isr_handler_t isr_handlers[256];

extern void isr_common(u8 interrupt);

#define STRINGIFY(x) #x
#define PRINT_REG(x) puts(STRINGIFY(x)"=", 0x04); putn(regs->x, 16, 0x0C);

void isr_handler(x86_registers_t* regs) {
	if (regs->interrupt < 256 && isr_handlers[regs->interrupt] != NULL) {
		isr_handlers[regs->interrupt](regs);
	} else {
		puts("registers:\n", 0x07);
		PRINT_REG(edi)
		puts(", ", 0x0C);
		PRINT_REG(esi)
		puts(", ", 0x0C);
		PRINT_REG(ebp)
		puts(", ", 0x0C);
		PRINT_REG(esp)
		puts(", ", 0x0C);
		PRINT_REG(ebx)
		puts(", ", 0x0C);
		PRINT_REG(edx)
		puts(", ", 0x0C);
		PRINT_REG(ecx)
		puts(", ", 0x0C);
		PRINT_REG(eax)
		putc('\n', 0x0C);
		PRINT_REG(interrupt)
		puts("\n", 0x0C);
		PRINT_REG(eip)
		puts(", ", 0x0C);
		PRINT_REG(cs)
		puts(", ", 0x0C);
		PRINT_REG(eflags)
		putc('\n', 0x0C);

		if (regs->interrupt < 32) {
			puts("Unhandled exception: ", 0xC0);
			puts(exceptions[regs->interrupt], 0xC0);
			puts("\nStack trace:\n", 0xC0);

			for (u32 esp = regs->esp + 16; esp <= regs->ebp; esp += 4) {
				putn(esp, 16, 0x09);
				puts(": ", 0x0F);
				u32* ptr = ((u32*) esp);
				putn(*ptr, 16, 0x0C);
				putc('\n', 0x0F);
			}

			abort();
		} else {
			puts("Unhandled interrupt\n", 0x0F);
		}
	}
}

#include "isr_handlers.inl"

void isr_init(void) {
	#include "isr_handlers_register.inl"

	for (u16 i = 0; i < 255; ++i) {
		idt_enable(i);
	}
}

void isr_register(u8 interrupt, isr_handler_t handler) {
	isr_handlers[interrupt] = handler;
	idt_enable(interrupt);
}
