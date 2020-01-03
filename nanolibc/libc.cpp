#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct mbstate_t;

[[noreturn]] void trap() {
	__builtin_unreachable();
}

extern "C" {

// Will be provided by Javascript.
void print_string(const char* str);

void* memcpy(void* dest, const void* src, size_t count) {
	for (size_t i = 0; i < count; ++i) {
		((char*) dest)[i] =  ((const char*) src)[i];
	}
	return dest;
}

void* memset (void * dest, int value, size_t count) {
	for (size_t i = 0; i < count; ++i) {
		((unsigned char*) dest)[i] =  (unsigned char) value;
	}
	return dest;
}

int puts ( const char * str ) {
	print_string(str);
	return 0;
}

}
