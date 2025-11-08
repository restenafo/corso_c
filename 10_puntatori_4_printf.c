#include <stdio.h>

int main(void) {
	char mystr[] = "AABBCCDDEEFF";
	char *p = mystr;
	printf("All'inizio p è %p\n", p);
	while (*p != 0) {
		putchar(*p);
		p++;
	}
        printf("\nAlla fine p è %p\n", p);
	return 0;
}
