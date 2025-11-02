#include <stdio.h>

void conta(int start, int end) {

iterate:
	if (start > end) return;
	printf("%d\n", start);
	start+=1;
	goto iterate;
}

int main(void) {
	conta(0,9);
	return 0;
}
