#pragma once
#include <arch/x86/drivers/cpubasics.h>
#include <arch/x86/hal/isr.h>
#include <arch/x86/hal/irq.h>
#include <std/stdio.h>

void pit_set_freq(size_t hz);
void pit_init();