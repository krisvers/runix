[bits 32]

extern isr_handler
global isr_common
isr_common:
	pusha

	xor eax, eax
	mov ax, ds
	push eax

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	push esp

	call isr_handler
	add esp, 4

	pop eax
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	popa
	add esp, 8
	iretd
