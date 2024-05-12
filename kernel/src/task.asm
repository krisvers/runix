[bits 32]

global task
task:
	mov eax, 0x00
	mov ebx, 'K'
	mov ecx, 0x02
	int 0x80
	jmp $
