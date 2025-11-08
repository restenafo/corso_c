#include <stdio.h>

int main(void){
	char str[] = "aabb";
	short *s = (short*)str;
	printf("%d %d\n", s[0], s[1]);
	printf("%d %d\n", str[0], str[1]);
	return 0;
}
