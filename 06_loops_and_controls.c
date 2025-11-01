#include <stdio.h>

int space(void) {
	printf("\n");
	return 0;
}

int if_block(void) {
	printf("** sezione IF **\n");
	int i = 5;
	if (i > 3) {
		printf("%s\n", "i è maggiore di 3");
	}
	else {
		printf("%s", "i è minore o uguale di 3");
	}
	return 0;
}

int block_block(void) {
	printf("** sezione BLOCK **\n");
	int i = 8;
	{
		int i=5;
		printf("i vale %d\n",i);
		printf("l'indirizzo di i è %p\n", &i);
	}
	printf("i vale %d\n",i);
	printf("l'indirizzo di i è %p\n", &i);
	return 0;
}

int main(void) {
	if_block();
	space();
	block_block();
	return 0;
}
