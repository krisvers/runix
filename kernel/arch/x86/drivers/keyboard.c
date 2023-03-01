#include <arch/x86/drivers/keyboard.h>

static char buffer[256];
static uint8_t index = 0;

static bool ps2_wait_read() {
    for (uint32_t i = 0; i < 0xFFFFF; i++) {
        if ((inb(0x64) & 0x1) == 0x0) {
            return true;
        }
    }
    //printf("ps/2 wait write timeout\n");
    return false;
}

static char keycodes[128] = {
	0,   27,  '1', '2', '3', '4', '5', '6', '7', '8', '9',  '0', '-',  '=',  '\b', '\t',                                                    /* <-- Tab */
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[',  ']', '\n', 0,                                                                   /* <-- control key */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,    '\\', 'z',  'x',  'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, /* Alt */
    ' ',                                                                                                                                    /* Space bar */
    0,                                                                                                                                      /* Caps lock */
    0,                                                                                                                                      /* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,   0,                                                                                              /* < ... F10 */
    0,                                                                                                                                      /* 69 - Num lock*/
    0,                                                                                                                                      /* Scroll Lock */
    0,                                                                                                                                      /* Home key */
    0,                                                                                                                                      /* Up Arrow */
    0,                                                                                                                                      /* Page Up */
    '-', 0,                                                                                                                                 /* Left Arrow */
    0,   0,                                                                                                                                 /* Right Arrow */
    '+', 0,                                                                                                                                 /* 79 - End key*/
    0,                                                                                                                                      /* Down Arrow */
    0,                                                                                                                                      /* Page Down */
    0,                                                                                                                                      /* Insert Key */
    0,                                                                                                                                      /* Delete Key */
    0,   0,   0,   0,                                                                                                                       /* F11 Key */
    0,                                                                                                                                      /* F12 Key */
    0,                                                                                                                                      /* All other keys are undefined */
};

static char keycodes_shift[128] = {
    0,   27,  '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_',  '+', '\b', '\t',                                                    /* <-- Tab */
    'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'P', '{', '}', '\n', 0,                                                                  /* <-- control key */
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '?', 0,   0,    '|', 'Z',  'X',  'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0, '*', 0, /* Alt */
    ' ',                                                                                                                                  /* Space bar */
    0,                                                                                                                                    /* Caps lock */
    0,                                                                                                                                    /* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,   0,                                                                                            /* < ... F10 */
    0,                                                                                                                                    /* 69 - Num lock*/
    0,                                                                                                                                    /* Scroll Lock */
    0,                                                                                                                                    /* Home key */
    0,                                                                                                                                    /* Up Arrow */
    0,                                                                                                                                    /* Page Up */
    '-', 0,                                                                                                                               /* Left Arrow */
    0,   0,                                                                                                                               /* Right Arrow */
    '+', 0,                                                                                                                               /* 79 - End key*/
    0,                                                                                                                                    /* Down Arrow */
    0,                                                                                                                                    /* Page Down */
    0,                                                                                                                                    /* Insert Key */
    0,                                                                                                                                    /* Delete Key */
    0,   0,   0,   0,                                                                                                                     /* F11 Key */
    0,                                                                                                                                    /* F12 Key */
    0,                                                                                                                                    /* All other keys are undefined */
};

static bool shift_pressed = false;

static char poll_key_char() {
	char keycode = inb(0x60);
	if ((keycode == 0x2A) || (keycode == 0x36)) {
		return -2;
	}
	if (keycode > 0) {
		if (shift_pressed) {
			return keycodes_shift[(unsigned char) keycode];
		}
		return keycodes[(unsigned char) keycode];
	}
	return -1;
}

void keyboard_handler(Registers * regs) {
    char c = 0;
    pic_send_eoi();
    inb(0x60);
    if (ps2_wait_read()) {
        c = poll_key_char();
        if (c == '\b') {
            putc('\b');
            buffer[index] = 0;
            index--;
        } else if (c == '\n') {
            putc('\n');
            buffer[0] = 0;
            index = 0;
        } else if (c == '\t') {
            putc('\t');
            buffer[index] = ' ';
            index++;
        } else if (c > 0) {
            putc(c);
            buffer[index] = c;
            index++;
        }
    }
}

char * keyboard_buffer() {
    return &buffer;
}

void keyboard_init() {
    putcolor(LIGHT_GREY);
    printf("ps/2 keyboard initialized [");
    putcolor(GREEN);
    printf("*");
    putcolor(LIGHT_GREY);
    printf("]\n\t");
    printf("layout: qwerty\n");
    irq_reg_handler(1, keyboard_handler);
}