#ifndef KROS_X86_IDT_H
#define KROS_X86_IDT_H

#include <types.h>

#define IDT_CODE_SEGMENT 0x08

#define IDT_GATE_TASK 0x05
#define IDT_GATE_16_BIT_INT 0x06
#define IDT_GATE_16_BIT_TRAP 0x07
#define IDT_GATE_32_BIT_INT 0x0E
#define IDT_GATE_32_BIT_TRAP 0x0F

#define IDT_RING_0 0x00
#define IDT_RING_1 0x20
#define IDT_RING_2 0x40
#define IDT_RING_3 0x80

#define IDT_GATE_PRESENT 0x80

typedef void (*idt_handler_t)(u8 interrupt);

void idt_init(void);
void idt_enable(u8 interrupt);
void idt_disable(u8 interrupt);
void idt_register(u8 interrupt, idt_handler_t base, u16 segment, u8 flags);

#endif
