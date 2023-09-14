[bits 32]

extern ckernel

global kernel
kernel:
	jmp ckernel

	jmp $
