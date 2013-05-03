#ifndef _SYMBOLTABLE
#define _SYMBOLTABLE

typedef struct SymbolItem SymbolItem;
#include "public.h"

struct SymbolItem{
	//TODO:to be motify
//	void* value;
	int name;
	char* value;
};

typedef struct SymbolTable{
	//TODO:to construct a construction to organize the symbolItem
	//TODO:here should be a Hash Table
	int num;
	
}SymbolTable;

int tableSize;			//mark down how big is this symbolList
SymbolItem* itemList;		//temporarily be the storage construct of the symbolTable

int iNum;						//the amount of the item now
void oneMoreSymbol();	//iNum++

SymbolItem keyWord[] = 
{
	{INT,"int"},{CHAR,"char"},{FLOAT,"float"},{STRING, "string"},
	{WHILE,"while"},{FOR,"for"},{IF,"if"},{ELSE,"else"}
};
#endif