#include <stdio.h>

int main(void){
	int a[5] = {10, 5, 8, 1000, 54};
	printf("%d %d %d\n", a[0], a[2], a[4]);
	int x = 5;
	char str[6] = {'h', 'e', 'l', 'l', 'o', 0};

	/*
	* stringa senza il numero 0 finale (che è il "terminatore nullo" necessario per indicare la fine di una stringa).
	* Senza il terminatore, viene aggiunto ciò che viene trovato in memoria (caratteri indesiderati).
	*/
	char str2[6] = {'w', 'o', 'r', 'l', 'd', '0'};
	int y = 6;
	printf("Prima esecuzione:\n");
	printf("%s -- Stringa CON 'null terminator' alla fine\n", str);
        printf("%s -- Stringa SENZA 'null terminator' alla fine \n", str2);
	printf("Size of 'str' is %lu\n", sizeof(str));
        printf("Size of 'str2' is %lu\n", sizeof(str2));
	return 0;

}
