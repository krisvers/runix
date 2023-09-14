ENTRY(kernel)

SECTIONS
{
	. = 0x7E00;

	.text : {
		*(.text)
	}

	.data ALIGN(4096) : {
		*(.data)
	}

	.rodata ALIGN(4096) : {
		*(.rodata)
	}

	.bss ALIGN(4096) : {
		*(.bss)
	}
}
