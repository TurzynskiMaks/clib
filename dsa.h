#ifndef DYNAMIC_STRING_ARRAY_H
#define DYNAMIC_STRING_ARRAY_H

typedef struct {
	char** items;
	int size;
	int amount;
} dynamicStringArray;

__declspec(dllexport) int checkArray(dynamicStringArray* array);
__declspec(dllexport) int initDSA(dynamicStringArray *array, int initialSize);
__declspec(dllexport) int addStringToDSA(dynamicStringArray *array, const char* string);
__declspec(dllexport) int updateStringInDSA(dynamicStringArray* array, int index, const char* string);
__declspec(dllexport) char* getStringInDSA(dynamicStringArray* array, int index);
__declspec(dllexport) int removeStringInDSA(dynamicStringArray* array, int index);
__declspec(dllexport) int clearDSA(dynamicStringArray* array);
__declspec(dllexport) void freeDSA(dynamicStringArray* array);


/*
CRUD
create	addStringToDSA
read	getStringInDSA
update	updateStringInDSA
delete	removeStringInDSA
*/

#endif