#include <arch/x86/drivers/pci.h>

static uint8_t * const info_addr = ((uint8_t *) 0x500);
static bool pci_found = false;
static uint8_t config;
static uint8_t num_devices;

void pci_init() {
	if (!(info_addr[0] & 0b10000000)) {
		printf("PCI: no bus found!\n");
		return;
	}

	pci_found = true;
	config = info_addr[1];
	num_devices = info_addr[0];
	printf("PCI: configuration: %x, number of devices: %x\n", config, num_devices);
}
