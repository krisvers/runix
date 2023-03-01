#include <arch/x86/hal/pit.h>

static size_t mseconds = 0;

static void timer_handler(Registers * regs) {
    mseconds++;
    pic_send_eoi();
}

void pit_set_freq(size_t hz) {
    size_t div = 3579545 / (hz * 3);
    outb(0x43, 0x36);
    outb(0x40, div & 0xFF);
    outb(0x40, div >> 8);
}

void pit_init() {
    pit_set_freq(1000);
    putcolor(LIGHT_GREY);
    printf("pit initialized [");
    putcolor(GREEN);
    printf("*");
    putcolor(LIGHT_GREY);
    printf("]\n\t");
    printf("hz: %d, ms: %d\n", 1000, mseconds);
    irq_reg_handler(0, timer_handler);
}