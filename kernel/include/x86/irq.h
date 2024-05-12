#ifndef KROS_X86_IRQ_H
#define KROS_X86_IRQ_H

#include <types.h>
#include <x86/common.h>

typedef void(*irq_handler_t)(x86_registers_t*);

void irq_init(void);
void irq_register(u8 irq, irq_handler_t handler);

#endif
