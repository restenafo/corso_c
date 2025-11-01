#include <stdio.h>

void stampa(char stringa[], char a[], char b[]) {
	printf("%s esecuzione\n", stringa);
	printf("%s\n", a);
	printf("%s\n", b);
	printf("\n");
}

int main(void){
	int a[5] = {10, 5, 8, 1000, 54};
	printf("%d %d %d\n", a[0], a[2], a[4]);
	char str[7] = {'h', 'e', 'l', 'l', 'o', '!'};   // stringa senza il numero 0 finale (che è il "terminatore nullo" necessario per indicare la fine di una stringa).
							// Senza il terminatore, viene aggiunto ciò che viene trovato in memoria (caratteri indesiderati).
	char str2[6] = {'w', 'o', 'r', 'l', 'd', 0};
	stampa("Prima", str, str2);
	stampa("Seconda", str, str2);
	return 0;
}
