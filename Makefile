all: $(subst .asm,asm.o,$(shell find ./kernel -type f -name "*.asm")) $(subst .c,c.o,$(shell find ./kernel -type f -name "*.c"))
	ld -Tlinker.ld $(shell find . -type f -name "*.o") -o bin/kernel.elf -melf_i386
	objcopy -O binary bin/kernel.elf bin/kernel.bin
	nasm -f bin boot.asm -o bin/boot.bin
	cat bin/boot.bin bin/kernel.bin > disk.img

clean:
	rm -rf bin/* obj/*

run:
	qemu-system-i386 -fda disk.img -no-shutdown -no-reboot -d int -D log.txt

%asm.o: %.asm
	nasm -f elf32 $< -o obj/$(subst /,_,$@)

%c.o: %.c
	clang $< -o obj/$(subst /,_,$@) -Wl,-Tlinker.ld -nostdlib -g -Wall -Wextra -Wpedantic -fno-common -fno-stack-protector -mno-implicit-float -m32
