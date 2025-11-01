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

int block_goto(void) {
	printf("** sezione GOTO **\n");
	int i = 0;

again:
	printf("%d\n",i);
	i++;
	if (i < 10) goto again;
	return 0;
}

int block_while(void) {
	printf("** sezione WHILE **\n");
	int i = 0;
	while (i < 10) {
		printf("%d\n",i);
		i++;
	}
	return 0;
}

int block_goto_2(void) {
	printf("** sezione GOTO loop 2\n");
	int i = 0;
loop:
	if (!(i < 10)) goto next;
	printf("%d\n",i);
	i++;
	goto loop;
next:
	return 0;
}

void conta(int start, int end) {
	if (start > end) return;
	printf("%d\n", start);
	conta(start + 1, end); 
}

int block_recursion(void) {
	printf("** sezione RECURSION **\n");
	conta(0,9);
	return 0;
}

int main(void) {
	if_block();
	space();
	block_block();
	space();
	block_goto();
	space();
	block_while();
	space();
	block_goto_2();
	space();
	block_recursion();
	return 0;
}
