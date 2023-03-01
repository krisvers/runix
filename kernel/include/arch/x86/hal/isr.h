#pragma once
#include <std/stdio.h>
#include <std/types.h>
#include <std/stdlib.h>
#include <arch/x86/hal/idt.h>
#include <arch/x86/hal/gdt.h>

typedef struct {
    uint32_t ds;
    uint32_t edi, esi, ebp, kern_esp, ebx, ecx, edx, eax;
    uint32_t interrupt, error;
    uint32_t eip, cs, cflags, esp, ss;
} __attribute__((packed)) Registers;

typedef void (*ISRHandler) (Registers* regs);

void isr_init();
void isr_reg_handler(int interrupt, ISRHandler handler);
