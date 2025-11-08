#include <stdio.h>

int main(void) {
	int x = 5;
	int *y = &x;
	int **z = &y;
	printf("x vive in %p e vale %d\n", y, x);
        printf("x vive in %p e vale %d\n", &x, x);
	printf("x vive in %p e y vive in %p\n", y, z);
	printf("%d, %d, %d\n", (int)sizeof(x),(int)sizeof(y),(int)sizeof(z));
	return 0;
}
