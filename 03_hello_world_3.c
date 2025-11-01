#include <stdio.h>

int clear(void) {
        printf("\x1b[2J\x1b[H");
}

int main(void) {
	clear();
	printf("Hello World\n");
	return 0;
}
