#include <mem.h>

void memcpy(void* dst, void* src, usize size) {
	while (size--) {
		*((u8*) dst) = *((u8*) src);
		dst = (void*) (((uptr) dst) + 1);
		src = (void*) (((uptr) src) + 1);
	}
}

void memmov(void* dst, void* src, usize size) {
	while (size--) {
		*((u8*) dst) = *((u8*) src);
		dst = (void*) (((uptr) dst) + 1);
		src = (void*) (((uptr) src) + 1);
	}
}

void memset(void* dst, u8 value, usize size) {
	while (size--) {
		*((u8*) dst) = value;
		dst = (void*) (((uptr) dst) + 1);
	}
}

void strcpy(char* dst, char* src, usize size) {
	memcpy(dst, src, size);
}

usize strcmp(char* first, char* second) {
	usize diff = 0;
	while (*first != '\0' && *second != '\0' && diff == 0) {
		diff = *first - *second;

		first = (void*) (((uptr) first) + 1);
		second = (void*) (((uptr) second) + 1);
	}
	return diff;
}

usize strncmp(char* first, char* second, usize length) {
	usize diff = 0;
	while (length-- && diff == 0) {
		diff = *first - *second;

		first = (void*) (((uptr) first) + 1);
		second = (void*) (((uptr) second) + 1);
	}
	return diff;
}
