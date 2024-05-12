#include <x86/idt.h>

typedef struct idt_entry_t {
	u16 base_low;
	u16 segment;
	u8 reserved;
	u8 flags;
	u16 base_high;
} __attribute__((packed)) idt_entry_t;

typedef struct idtr_t {
	u16 limit;
	void* base;
} __attribute__((packed)) idtr_t;

static idt_entry_t idt_entries[256];

static idtr_t idtr = {
	.limit = sizeof(idt_entries) - 1,
	.base = idt_entries
};

void idt_load(idtr_t* idt_desc);

void idt_init(void) {
	idt_load(&idtr);
}

void idt_enable(u8 interrupt) {
	idt_entries[interrupt].flags |= IDT_GATE_PRESENT;
}

void idt_disable(u8 interrupt) {
	idt_entries[interrupt].flags &= ~IDT_GATE_PRESENT;
}

void idt_register(u8 interrupt, idt_handler_t base, u16 segment, u8 flags) {
	u32 b = ((u32) base);
	idt_entries[interrupt].base_low = b & 0xFFFF;
	idt_entries[interrupt].segment = segment;
	idt_entries[interrupt].reserved = 0;
	idt_entries[interrupt].flags = flags;
	idt_entries[interrupt].base_high = (b >> 16) & 0xFFFF;
}
