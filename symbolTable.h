#ifndef _SYMBOLTABLE
#define _SYMBOLTABLE

typedef struct SymbolItem SymbolItem;
#include "public.h"

struct SymbolItem{		//�������˹ؼ��ֱ����ˡ����ͷ��ű�û��ϵ����
	//TODO:to be motify
//	void* value;
	int name;
	char* value;
};

typedef struct SymbolTableItem{
	//TODO:here should be a Hash Table
	char * name;				//����
	int kind;						//���ࣨ���������顢����
	int classs;					//�������� ָ��
	int address;				//��ַƫ��
	void* extend;				//��չ����
}SymbolTableItem;
#define ORIGINALSTSIZE 64

typedef struct SymbolTable{
	char* tableName;						//������ű������
	SymbolTableItem *stItems;		//���ű�
	int now;										//����ָ��ķ��ű���Ŀ
//	int length;									//ʵ��ӵ�еķ�������Ŀ
	int size;										//���õ��ڴ��С
	int fatherTable;							//��������father��������ı��
	int childTable;							//��һ��table������ı��
}SymbolTable;
int initSymbolTable(SymbolTable* table, char* name);

typedef struct STGroup{
	SymbolTable *stTables;			//a group of symbol table
	int length;
	int size;										
	int newTable;								//point to the newest table created just now, ������ʾ�ձ�empty Table for non-function block
	int nowTable;								//point to which table we are using now
}STGroup;
STGroup stGroup;
int initSTGroup();

typedef struct STID{
	SymbolTableItem *pstItem;
	int itemNum;					//item number in SymbolTable:������ţ���������ַ�Ļ������ﱣ���ַ
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