#include "dsa.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

int checkArray(dynamicStringArray* array) {
	if (array == NULL || array->items == NULL) return -1;
	return 0;
}

int initDSA(dynamicStringArray* array, int initialSize) {
	if (array == NULL || initialSize <= 0) return -1;
	array->items = calloc(initialSize, sizeof(char*));

	if (array->items == NULL) {
		array->size = 0;
		array->amount = 0;
		return -2;
	}

	array->size = initialSize;
	array->amount = 0;
	return 0;
}

int addStringToDSA(dynamicStringArray* array, const char* string) {
	if (checkArray(array) != 0) return -1;

	if (array->amount == array->size) {
		int newSize = (array->size == 0) ? 2 : array->size * 2;
		
		char** temp = realloc(array->items, newSize * sizeof(char*));

		if (temp == NULL) return -2;
		
		array->size = newSize;

		array->items = temp;

		for (int i = array->amount; i < newSize; i++) {
			array->items[i] = NULL;
		}
	}

	size_t length = strlen(string) + 1;

	array->items[array->amount] = malloc(length * sizeof(char));

	if (array->items[array->amount] == NULL) return -2;

	snprintf(array->items[array->amount], length, "%s", string);

	array->amount++;

	return 0;
}

int updateStringInDSA(dynamicStringArray* array, int index, const char* string) {
	if (checkArray(array) != 0) return -1;
	if ((array->amount - 1) < index || index < 0) return -1;

	size_t length = strlen(string) + 1;

	char* temp = realloc(array->items[index], length * sizeof(char));
	if (temp == NULL) return -2;
	array->items[index] = temp;

	
	snprintf(array->items[index], length, "%s", string);

	return 0;
}

char* getStringInDSA(dynamicStringArray* array, int index) {
	if (checkArray(array) != 0) return NULL;
	if ((array->amount - 1) < index || index < 0) return NULL;

	char* temp = array->items[index];
	if (temp == NULL) return NULL;
	
	return temp;
}

int removeStringInDSA(dynamicStringArray* array, int index) {
	if (checkArray(array) != 0) return -1;
	if ((array->amount - 1) < index || index < 0) return -1;

	free(array->items[index]);

	for (int i = index; i < array->amount -1; i++) {
		array->items[i] = array->items[i + 1];
	}

	array->items[array->amount - 1] = NULL;
	array->amount--;

	return 0;
}

int clearDSA(dynamicStringArray* array) {
	if (array == NULL || array->items == NULL) return -1;
	for (int i = array->amount - 1; i >= 0; i--) {
		free(array->items[i]);
		array->items[i] = NULL;
	}
	array->amount = 0;
	return 0;
}

void freeDSA(dynamicStringArray* array) {
	clearDSA(array);
	if (array->items != NULL) {
		free(array->items);
	}
	array->items = NULL;
	array->amount = 0;
	array->size = 0;
}