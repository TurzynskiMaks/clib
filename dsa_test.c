#include"dsa.h"
#include<stdio.h>

int main() {
	dynamicStringArray array1;
	char* string1 = "Dupa\n";
	char* string2 = "Cyce\n";
	char* string3 = "Wadowice\n";
	char* stringT = "Kremuweczka\n";
	initDSA(&array1, 5);
	printf("Inicjalizacja good\n");
	addStringToDSA(&array1, string1);
	addStringToDSA(&array1, string2);
	addStringToDSA(&array1, string3);
	printf("Test dodawania\n");
	for (int i = 0; i < 3; i++) {
		printf("%s\n", getStringInDSA(&array1, i));
	}
	printf("Test aktualizacji\n");
	updateStringInDSA(&array1, 2, stringT);
	for (int i = 0; i < 3; i++) {
		printf("%s\n", getStringInDSA(&array1, i));
	}
	printf("Test usuwania\n");
	removeStringInDSA(&array1, 0);
	printf("%s\n", getStringInDSA(&array1, 0));
	freeDSA(&array1);
}