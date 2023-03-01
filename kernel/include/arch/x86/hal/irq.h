#pragma once
#include <std/stdio.h>
#include <arch/x86/hal/pic.h>
#include <arch/x86/hal/isr.h>
#include <arch/x86/drivers/cpubasics.h>

typedef void (*IRQHandler)(Registers * regs);

void irq_init();
void irq_reg_handler(int irq, IRQHandler handler);
