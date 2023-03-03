#include <arch/x86/hal/gdt.h>
#include <arch/x86/hal/idt.h>
#include <arch/x86/hal/isr.h>
#include <arch/x86/hal/irq.h>
#include <arch/x86/hal/pic.h>
#include <arch/x86/hal/pit.h>
#include <std/stdio.h>
#include <std/stdlib.h>
#include <arch/x86/drivers/cpubasics.h>
#include <arch/x86/drivers/tty.h>
#include <arch/x86/drivers/vga.h>
#include <arch/x86/drivers/keyboard.h>
#include <arch/x86/drivers/pci.h>
#include <std/stdbool.h>

static char * art =
".      .              ,cc.\n"
"H ,dP  HdRH.  ,cOc,  A`  `\n"
"HDP`   H`  o  H   H   `*o.\n"
"H `Tb  H      `QoP`  ~c.d`    :)\n"
"\n";

struct page_descriptor {
	size_t size;
	uint8_t * start;
	uint32_t first_free;
};

#define MAX_PAGE_NUMBER 256

uint8_t * pages_start = 0x100000;
uint16_t last_page = 0;
struct page_descriptor * pages[MAX_PAGE_NUMBER];

void * kmalloc(size_t size) {
	struct page_descriptor * current;
	current->size = size;
	current->first_free = 0;
	current->start = pages_start;
	pages_start += size;
	
	if (last_page >= MAX_PAGE_NUMBER) {
		return NULL;
	}

	pages[last_page++] = current;

	printf("kmalloced %i bytes!\n", size);

	return current;
}

void kfree(void * ptr, size_t size) {
	
}

void main() {
    putcolor(BLUE);
    printf("welcome to kros!\n");
    printf("%s", art);

	gdt_init();
	idt_init();
	isr_init();
	irq_init();
    pit_init();
    pci_init();
    keyboard_init();

    struct page_descriptor * test = kmalloc(4096);
    
    putcolor(WHITE);
    printf("\n");

	while (1) {

	}
}
