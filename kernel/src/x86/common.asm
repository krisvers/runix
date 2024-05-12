[bits 32]

global int_enable
int_enable:
	sti
	ret

global int_disable
int_disable:
	cli
	ret

global int_is_enabled
int_is_enabled:
	pushf
	pop ax
	and eax, 0x0200
	ret

global nmi_enable
nmi_enable:
	push ax
	in al, 0x70
	and al, 0x7F
	out 0x70, al
	in al, 0x70
	pop ax
	ret

global nmi_disable
nmi_disable:
	push ax
	in al, 0x70
	or al, 0x80
	out 0x70, al
	in al, 0x70
	pop ax
	ret
	
global inb
inb:
	push ebp
	mov ebp, esp

	push dx

	mov dx, [ebp + 8]
	xor eax, eax
	in al, dx

	pop dx

	pop ebp
	ret
	
global inw
inw:
	push ebp
	mov ebp, esp

	push dx

	mov dx, [ebp + 8]
	xor eax, eax
	in ax, dx

	pop dx

	pop ebp
	ret
	
global ind
ind:
	push ebp
	mov ebp, esp

	push dx

	mov dx, [ebp + 8]
	xor eax, eax
	in eax, dx

	pop dx

	pop ebp
	ret

global outb
outb:
	push ebp
	mov ebp, esp

	push dx
	push ax

	mov dx, [ebp + 8]
	mov al, [ebp + 12]

	out dx, al

	pop ax
	pop dx

	pop ebp
	ret

global outw
outw:
	push ebp
	mov ebp, esp

	push dx
	push ax

	mov dx, [ebp + 8]
	mov ax, [ebp + 12]

	out dx, ax

	pop ax
	pop dx

	pop ebp
	ret

global outd
outd:
	push ebp
	mov ebp, esp

	push dx
	push eax

	mov dx, [ebp + 8]
	mov eax, [ebp + 12]

	out dx, eax

	pop eax
	pop dx

	pop ebp
	ret

global iowait
iowait:
	mov al, 0x00
	out 0x80, al
	ret

global abort
abort:
	cli
	hlt
