#ifndef KROS_X86_COMMON_H
#define KROS_X86_COMMON_H

#include <types.h>

typedef struct x86_registers_t {
	u32 ds;
	u32 edi, esi, ebp, kern_esp, ebx, edx, ecx, eax;
	u32 eip, cs, cflags, esp, ss;
	u32 interrupt;
} __attribute__((packed)) x86_registers_t; 

extern void int_enable(void);
extern void int_disable(void);

extern void nmi_enable(void);
extern void nmi_disable(void);

extern u8 inb(u16 port);
extern u16 inw(u16 port);
extern u32 ind(u16 port);

extern void outb(u16 port, u8 value);
extern void outw(u16 port, u16 value);
extern void outd(u16 port, u32 value);

#endif
