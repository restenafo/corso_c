#include <stdio.h>

int main(void) {
	char mystr[] = "Hello World";
	char *p = mystr;	// in C il nome dell'array è il puntatore dell'arrey
	printf("All'indirizzo %p, posso vedere: %s\n", mystr, mystr);
	printf("%c%c\n", p[0],p[1]);
        printf("%c%c\n", *p,*(p+1));

	char mystr2[] = "AABBCCDDEEFF";
	short *q = (short*)mystr2;
	printf("%d\n", *q);
	return 0;
}
