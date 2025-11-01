#include <stdio.h>
#include <limits.h>

int main(void) {
	int x = 5;
	printf("Hello World: int is %lu bytes\n", sizeof(x));
	printf("Hello World: int min: %d, int max: %d\n",
		INT_MIN, INT_MAX);
	char c = 1; // intero 8 bit, 1 byte.
	short s = 2000; // intero 16 bit, 2 byte.
	int i = 5; // intero 32 bit, 4 byte.
	long l = 19; // intero 64 bit, 8 byte.

	printf("Long is %lu bytes\n", sizeof(l));
	return 0;
}
