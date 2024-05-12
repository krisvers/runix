ENTRY(ckernel)

KERNEL_BASE = 0x7E00;

MEMORY
{
	ram (rwx) : org = KERNEL_BASE, l = 51200
}

SECTIONS
{
	. = KERNEL_BASE;

	.entry (KERNEL_BASE) : {
		*(.entry)
	} > ram

	.text : {
		*(.text)
	} > ram

	.data ALIGN(4096) : {
		*(.data)
	} > ram

	.rodata ALIGN(4096) : {
		*(.rodata)
	} > ram

	.bss ALIGN(4096) : {
		_BSS_START = ABSOLUTE(.);
		*(.bss)
		_BSS_END = ABSOLUTE(.);
	} > ram
}
