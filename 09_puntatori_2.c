#include <stdio.h>

void incr(int *p) {
	*p = *p +1;
}

int main(void) {
	int x = 5;
	int *y = NULL;
	printf("X valeva: %d\n", x);

	y = &x;
	incr(y);
	incr(y);
	printf("X adesso vale: %d\n", x);
	incr(y);
        printf("X adesso vale: %d\n", x);
}
