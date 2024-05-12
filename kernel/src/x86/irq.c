#include <x86/irq.h>
#include <x86/isr.h>
#include <x86/common.h>
#include <types.h>
#include <print.h>
#include <def.h>

#define PIC_MASTER_COMMAND 0x20
#define PIC_MASTER_DATA 0x21
#define PIC_SLAVE_COMMAND 0xA0
#define PIC_SLAVE_DATA 0xA1

#define PIC_CMD_EOI 0x20
#define PIC_CMD_READ_IRR 0x0A
#define PIC_CMD_READ_ISR 0x0A

#define ICW1_ICW4 0x01
#define ICW1_CASCADE 0x02
#define ICW1_INTERVAL4 0x04
#define ICW1_LEVEL 0x08
#define ICW1_INIT 0x10

#define ICW4_8086 0x01
#define ICW4_AUTO 0x02
#define ICW4_BUFFER_SLAVE 0x08
#define ICW4_BUFFER_MASTER 0x0C
#define ICW4_FULLY_NESTED 0x10

#define PIC_MASTER_REMAP 0x20
#define PIC_SLAVE_REMAP 0x28

void pic_disable(void) {
	outb(PIC_MASTER_DATA, 0xFF);
	outb(PIC_SLAVE_DATA, 0xFF);
}

void pic_remap(u32 master_offset, u32 slave_offset) {
	u8 master_mask = inb(PIC_MASTER_DATA);
	u8 slave_mask = inb(PIC_SLAVE_DATA);

	outb(PIC_MASTER_COMMAND, ICW1_INIT | ICW1_ICW4);
	iowait();
	outb(PIC_SLAVE_COMMAND, ICW1_INIT | ICW1_ICW4);
	iowait();
	outb(PIC_MASTER_DATA, master_offset);
	iowait();
	outb(PIC_SLAVE_DATA, slave_offset);
	iowait();
	outb(PIC_MASTER_DATA, 0x04);
	iowait();
	outb(PIC_SLAVE_DATA, 0x02);
	iowait();

	outb(PIC_MASTER_DATA, ICW4_8086 | ICW4_AUTO);
	iowait();
	outb(PIC_SLAVE_DATA, ICW4_8086 | ICW4_AUTO);
	iowait();

	outb(PIC_MASTER_DATA, master_mask);
	outb(PIC_SLAVE_DATA, slave_mask);
}

void pic_mask(u8 irq) {
	u8 port;

	if (irq < 8) {
		port = PIC_MASTER_DATA;
	} else {
		irq -= 8;
		port = PIC_SLAVE_DATA;
	}

	u8 mask = inb(port);
	outb(port, mask | (1 << irq));
}

void pic_unmask(u8 irq) {
	u8 port;

	if (irq < 8) {
		port = PIC_MASTER_DATA;
	} else {
		irq -= 8;
		port = PIC_SLAVE_DATA;
	}

	u8 mask = inb(port);
	outb(port, mask & ~(1 << irq));
}

u16 pic_read_irr(void) {
	outb(PIC_MASTER_COMMAND, PIC_CMD_READ_IRR);
	outb(PIC_SLAVE_COMMAND, PIC_CMD_READ_IRR);
	iowait();

	return inb(PIC_MASTER_COMMAND) | (inb(PIC_SLAVE_COMMAND) << 8);
}

u16 pic_read_isr(void) {
	outb(PIC_MASTER_COMMAND, PIC_CMD_READ_ISR);
	outb(PIC_SLAVE_COMMAND, PIC_CMD_READ_ISR);
	iowait();

	return inb(PIC_MASTER_COMMAND) | (inb(PIC_SLAVE_COMMAND) << 8);
}

static irq_handler_t irq_handlers[16];

void irq_handler(x86_registers_t* regs) {
	u32 irq = regs->interrupt - PIC_MASTER_REMAP;
	if (irq >= 16) {
		puts("Invalid IRQ ", 0x0F);
		putn(irq, 16, 0x0B);
		putc('\n', 0x00);

		abort();
	} else if (irq_handlers[irq] != NULL) {
		irq_handlers[irq](regs);
	} else {
		puts("Unhandled IRQ ", 0x0F);
		putn(irq, 16, 0x0B);
		putc('\n', 0x00);
	}
}

void irq_init(void) {
	pic_remap(PIC_MASTER_REMAP, PIC_SLAVE_REMAP);

	for (u8 i = 0; i < 16; ++i) {
		isr_register(PIC_MASTER_REMAP + i, irq_handler);
		pic_mask(i);
	}
}

void irq_register(u8 irq, irq_handler_t handler) {
	if (irq >= 16) {
		return;
	}

	irq_handlers[irq] = handler;
	pic_unmask(irq);
}
