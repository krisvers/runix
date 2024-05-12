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
#define PRINT_REG(x) puts(STRINGIFY(x)": ", 0x02); putn(regs->x, 16, 0x02); putc('\n', 0x02);

void isr_handler(x86_registers_t* regs) {
	PRINT_REG(ds)
	PRINT_REG(edi)
	PRINT_REG(esi)
	PRINT_REG(ebp)
	PRINT_REG(kern_esp)
	PRINT_REG(ebx)
	PRINT_REG(edx)
	PRINT_REG(ecx)
	PRINT_REG(eax)
	PRINT_REG(eip)
	PRINT_REG(cs)
	PRINT_REG(cflags)
	PRINT_REG(esp)
	PRINT_REG(ss)
	PRINT_REG(interrupt)

	while (1);
}

#include "isr_handlers.inl"

void isr_init(void) {
	#include "isr_handlers_register.inl"

	for (u16 i = 0; i < 255; ++i) {
		idt_enable(i);
	}
}
