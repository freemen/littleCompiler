#ifndef _SYMBOLTABLE
#define _SYMBOLTABLE

typedef struct SymbolItem SymbolItem;
#include "public.h"

struct SymbolItem{		//这个变成了关键字表项了。。和符号表没关系。。
	//TODO:to be motify
//	void* value;
	int name;
	char* value;
};

typedef struct SymbolTableItem{
	//TODO:here should be a Hash Table
	char * name;				//名字
	int kind;						//种类（变量、数组、函数
	int classs;					//数据类型 指针
	int address;				//地址偏移
	void* extend;				//拓展属性
}SymbolTableItem;
#define ORIGINALSTSIZE 64

typedef struct SymbolTable{
	char* tableName;						//这个符号表的名字
	SymbolTableItem *stItems;		//符号表
	int now;										//现在指向的符号表项目
//	int length;									//实际拥有的符号项数目
	int size;										//可用的内存大小
	int fatherTable;							//调用它的father表在组里的编号
	int childTable;							//下一个table在组里的编号
}SymbolTable;
int initSymbolTable(SymbolTable* table, char* name);

typedef struct STGroup{
	SymbolTable *stTables;			//a group of symbol table
	int length;
	int size;										
	int newTable;								//point to the newest table created just now, 负数表示空表，empty Table for non-function block
	int nowTable;								//point to which table we are using now
}STGroup;
STGroup stGroup;
int initSTGroup();

typedef struct STID{
	SymbolTableItem *pstItem;
	int itemNum;					//item number in SymbolTable:表中序号；如果代表地址的话，这里保存地址
	int tableNum;					//the number in the SymbolTableGroup, if it means address, it will be -1
}STID;

///////////////key word list///////////
int tableSize;			//mark down how big is this symbolList
SymbolItem* itemList;		//temporarily be the storage construct of the symbolTable

int iNum;						//the amount of the item now
void oneMoreSymbol();	//iNum++
void initKeyWordT();

/*extern SymbolItem keyWord[] = 
{
	{INT,"int"},{CHAR,"char"},{FLOAT,"float"}//,{STRING, "string"},
//	{WHILE,"while"},{FOR,"for"},{IF,"if"},{ELSE,"else"}
};*/
#endif