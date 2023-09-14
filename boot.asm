[bits 16]
org 0x7C00

%define KERN_SIZE 0x0020
%define KERN_OFFSET 0x7E00
%define KERN_SEGMENT 0x0000
%define INFO_OFFSET 0x0500

start:
	jmp .skip_bpb ; Workaround for some BIOSes that require this stub
	nop

	; Source: https://github.com/freebsd/freebsd-src/blob/82a21151cf1d7a3e9e95b9edbbf74ac10f386d6a/stand/i386/boot2/boot1.S
	.bpb:
	times 3-($-$$) db 0
	.bpb_oem_id:            db "KRISBOOT!"
	.bpb_sector_size:       dw 512
	.bpb_sects_per_cluster: db 0
	.bpb_reserved_sects:    dw 0
	.bpb_fat_count:         db 0
	.bpb_root_dir_entries:  dw 0
	.bpb_sector_count:      dw 0
	.bpb_media_type:        db 0
	.bpb_sects_per_fat:     dw 0
	.bpb_sects_per_track:   dw 18
	.bpb_heads_count:       dw 2
	.bpb_hidden_sects:      dd 0
	.bpb_sector_count_big:  dd 0
	.bpb_drive_num:         db 0
	.bpb_reserved:          db 0
	.bpb_signature:         db 0
	.bpb_volume_id:         dd 0
	.bpb_volume_label:      db "KRISBOOT!  "
	.bpb_filesystem_type:   times 8 db 0

	.skip_bpb:
		cli
		cld
		jmp .init

	.init:
; setup stack
	cli
	mov bp, 0x7C00
	xor ax, ax
	mov ds, ax
	mov es, ax
	mov ss, ax
	mov sp, bp
	sti

; reset disk
	mov ah, 0x00
	int 0x13

	xor ax, ax
	mov ds, ax
	
; enable the A20 line for full memory
	call enable_A20

; read next few sectors and run it (not good practice)
	mov ah, 0x02	; read mode for int 0x13
	mov al, KERN_SIZE	; sectors to read (sector = 512 bytes)
	mov ch, 0x00	; cylinder #
	mov cl, 0x02	; sector #
	mov dh, 0x00	; head #
	mov bx, KERN_SEGMENT
	mov es, bx		; 
	mov bx, KERN_OFFSET	; [es:bx] = [0x0:KERN_OFFSET]; where we load the kernel
	int 0x13
	
	.vid:
; setup video mode
;	0x03: text mode 80x25, 16 FG colors, 16 BG colors
	mov ah, 0x00
	mov al, 0x03
	int 0x10

; hide cursor
	mov ah, 0x01
	mov ch, 0x3F
	int 0x10

; compute gdtr
	xor eax, eax
	mov ax, ds ; segment
	shl eax, 4 ; multiply by 16
	add eax, GDT ; add offset
	mov [gdtr + 2], eax ; base
	mov eax, GDT_end ; compute limit
	sub eax, GDT
	sub eax, 1
	mov [gdtr], ax

; pass info to kernel
	; number of infos
	mov word [INFO_OFFSET], 1

	; name: "kernel address", id: 1
	mov word [INFO_OFFSET + 2], 1
	; length
	mov dword [INFO_OFFSET + 4], 8
	; data
	mov dword [INFO_OFFSET + 8], KERN_OFFSET
	mov dword [INFO_OFFSET + 12], KERN_SEGMENT

.load_gdt:
; load GDT
	cli
	lgdt [gdtr]

; protected mode
	mov eax, cr0
	or ax, 1 ; set protection enable bit
	mov cr0, eax

; set up segment registers
	mov ax, 0x10
	mov ds, ax
	mov fs, ax
	mov gs, ax
	mov es, ax
	mov ss, ax
	mov esp, 0x7FFF0 ; stack pointer at ~511KiB

	jmp dword 0x8:KERN_OFFSET

GDT:
	db 0, 0, 0, 0, 0, 0, 0, 0 ; null
	db 0xFF, 0xFF, 0x0, 0x0, 0x0, 0b10011010, 0b11001111, 0x0 ; Code segment
	db 0xFF, 0xFF, 0x0, 0x0, 0x0, 0b10010011, 0b11001111, 0x0 ; Data segment
GDT_end:

gdtr:
	dw 0 ; limit
	dd 0 ; base

error:
	mov ah, 0x0E
	mov al, 'E'
	xor bh, bh
	int 0x10

	mov al, 'R'
	int 0x10

	mov al, 'R'
	int 0x10

	hlt


enable_A20:
	cli

	call    a20wait
	mov     al, 0xAD
	out     0x64, al

	call    a20wait
	mov     al, 0xD0
	out     0x64, al

	call    a20wait2
	in      al, 0x60
	push    eax

	call    a20wait
	mov     al, 0xD1
	out     0x64, al

	call    a20wait
	pop     eax
	or      al, 2
	out     0x60, al

	call    a20wait
	mov     al, 0xAE
	out     0x64, al

	call    a20wait
	sti
	ret

a20wait:
	in      al,0x64
	test    al,2
	jnz     a20wait
	ret

a20wait2:
	in      al,0x64
	test    al,1
	jz      a20wait2
	ret

;	pack with zeroes
times 510-($-$$) db 0
;	magic number
dw 0xAA55
