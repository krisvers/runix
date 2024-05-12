#ifndef KROS_X86_ISR_H
#define KROS_X86_ISR_H

#include <x86/common.h>
#include <x86/idt.h>

typedef void (*isr_handler_t)(x86_registers_t*);

void isr_init(void);
void isr_register(u8 interrupt, isr_handler_t handler);

#endif
