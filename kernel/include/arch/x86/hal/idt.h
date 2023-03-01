#pragma once
#include <std/stdio.h>
#include <std/types.h>

typedef enum
{
    IDT_FLAG_GATE_TASK              = 0x5,
    IDT_FLAG_GATE_16BIT_INT         = 0x6,
    IDT_FLAG_GATE_16BIT_TRAP        = 0x7,
    IDT_FLAG_GATE_32BIT_INT         = 0xE,
    IDT_FLAG_GATE_32BIT_TRAP        = 0xF,

    IDT_FLAG_RING0                  = (0 << 5),
    IDT_FLAG_RING1                  = (1 << 5),
    IDT_FLAG_RING2                  = (2 << 5),
    IDT_FLAG_RING3                  = (3 << 5),

    IDT_FLAG_PRESENT                = 0x80,

} IDT_FLAGS;

void idt_init();
void idt_setgate(int interrupt, void* base, uint16_t segmentDescriptor, uint8_t flags);
void idt_disablegate(int interrupt);
void idt_enablegate(int interrupt);
void idt_setgate(int interrupt, void* base, uint16_t segmentDescriptor, uint8_t flags);
