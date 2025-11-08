#include <stdio.h>

int main(void) {
	int x = 5;
	int *y = NULL;
	printf("X vale: %d\n", x);

	y = &x;
	printf("X è registrato all'indirizzo: %p\n", y);

	*y = 10;
	//y[0] = 10;
	//y[1] = 10;
	printf("X adesso vale: %d\n", x);
	return 0;
}
