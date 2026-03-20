#ifndef DYNAMIC_STRING_ARRAY_H
#define DYNAMIC_STRING_ARRAY_H

typedef struct {
	char** items;
	int size;
	int amount;
} dynamicStringArray;

int checkArray(dynamicStringArray* array);
int initDSA(dynamicStringArray *array, int initialSize);
int addStringToDSA(dynamicStringArray *array, const char* string);
int updateStringInDSA(dynamicStringArray* array, int index, const char* string);
char* getStringInDSA(dynamicStringArray* array, int index);
int removeStringInDSA(dynamicStringArray* array, int index);
int clearDSA(dynamicStringArray* array);
void freeDSA(dynamicStringArray* array);


/*
CRUD
create	addStringToDSA
read	getStringInDSA
update	updateStringInDSA
delete	removeStringInDSA
*/

#endif