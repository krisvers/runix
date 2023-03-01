#include <arch/x86/hal/idt.h>

typedef struct
{
    uint16_t BaseLow;
    uint16_t SegmentSelector;
    uint8_t Reserved;
    uint8_t Flags;
    uint16_t BaseHigh;
} __attribute__((packed)) IDTEntry;

typedef struct
{
    uint16_t Limit;
    IDTEntry* Ptr;
} __attribute__((packed)) IDTDescriptor;


IDTEntry g_IDT[256];

IDTDescriptor g_IDTDescriptor = { sizeof(g_IDT) - 1, g_IDT };

void __attribute__((cdecl)) idt_load(IDTDescriptor* idtDescriptor);

void idt_setgate(int interrupt, void* base, uint16_t segmentDescriptor, uint8_t flags)
{
    g_IDT[interrupt].BaseLow = ((uint32_t)base) & 0xFFFF;
    g_IDT[interrupt].SegmentSelector = segmentDescriptor;
    g_IDT[interrupt].Reserved = 0;
    g_IDT[interrupt].Flags = flags;
    g_IDT[interrupt].BaseHigh = ((uint32_t)base >> 16) & 0xFFFF;
}

void idt_enablegate(int interrupt)
{
    g_IDT[interrupt].Flags |= IDT_FLAG_PRESENT;
}

void idt_disablegate(int interrupt)
{
    g_IDT[interrupt].Flags &= IDT_FLAG_PRESENT;
}

void idt_init()
{
    idt_load(&g_IDTDescriptor);
    putcolor(LIGHT_GREY);
    printf("idt initialized [");
    putcolor(GREEN);
    printf("*");
    putcolor(LIGHT_GREY);
    printf("]\n\t");
    printf("desc: %x\n", &g_IDTDescriptor);
}
