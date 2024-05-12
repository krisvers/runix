[bits 32]

global idt_load
idt_load:
	push ebp
	mov ebp, esp

	mov eax, [ebp + 8]
	lidt [eax]

	mov esp, ebp
	pop ebp
	ret
