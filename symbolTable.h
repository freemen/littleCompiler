#ifndef _SYMBOLTABLE
#define _SYMBOLTABLE

typedef struct SymbolItem SymbolItem;
#include "public.h"

struct SymbolItem{
	//TODO:to be motify
//	void* value;
	char* value;
	int name;
	//int pig;
};

typedef struct SymbolTable{
	//TODO:to construct a construction to organize the symbolItem
	//TODO:here should be a Hash Table
	int num;
	
}SymbolTable;

int tableSize;
SymbolItem* itemList;
int pItem;

#endif