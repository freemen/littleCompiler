#include "symbolTable.h"
SymbolItem keyWord[] = 
{
	{INT,"int"},{CHAR,"char"},{FLOAT,"float"},//,{STRING, "string"},
	{WHILE,"while"},{IF,"if"},{ELSE,"else"},/*,{FOR,"for"}*/
	{TRUE,"true"},{FALSE,"false"}
};
SymbolTable sTable;
void	initSymbolT(){
	initKeyWordT();
	initSTGroup();
}
	
	
void initKeyWordT(){				//it's a keyword table in fact
	tableSize = 128;
	itemList = (SymbolItem*)malloc(tableSize*(sizeof(SymbolItem)));
	
	iNum = sizeof(keyWord) >> 3;			//the sizeof(symbolItem) is 8
	memcpy(itemList, keyWord, sizeof(keyWord));
	int i=iNum;
	for(;i<tableSize;i++)
		itemList[i].value = "\0";
	logIt("symbolTable: initial %d symbol",iNum);
}



int add2SymbolT(Token *token, int length){
}
/*
*input: token: is the one which just be recognised
*					token->value is the word with '\0' in the end
*				lenght: is the real character amount in the word, without '\0'
*output: the index of this token in SymbolTable
*/
int checkAtKeyWordT(Token *token){
	//TODO:����������ȥһ����ƥ�䣬�Ժ�ȷ��ű����֮����Ҫ���㷨
	//�ðɣ����ڷ�����ֻ�ܵ����ؼ��ֱ�
	int i=0;
	SymbolItem it;
	for (i; i<iNum; i++){
		it = itemList[i];
		if (! strcmp((char*)token->value, it.value)){
			token->kind = it.name;
			token->value = it.value;
			logIt("symT: find %s in keyWordTable[%d]!type %d",(char*)token->value,i,token->kind);
			return i;					//����ҵ��ˣ���ʹ�÷��ű����һ��
		}
	}
	logIt("symT: a realId: %s",(char*)token->value);
/*	it = itemList[iNum];
	it.name = token->kind;
	it.value = (char*)malloc(sizeof(char)*(length+1));
	memcpy(it.value, token->value, (strlen(token->value)+1));
	logIt("symT: add a %s in symbolList[%d]",it.value,i);
	oneMoreSymbol();
	return i;							//�Ҳ������½�*/
}
/*
*		let the item number in Symbol table increace
*/
void oneMoreSymbol(){
	iNum++;
	if (iNum >= tableSize){	//���������飬�������޲���ֱ�Ӽӣ�ֻ�ܶ�̬����
		SymbolItem* tem = itemList;
		itemList = (SymbolItem*)realloc(itemList, sizeof(SymbolItem)*(tableSize<<1));
		if(itemList){
			logIt("symT: the symbolList is reallocated");
			int i = tableSize;
			memcpy(itemList, tem, tableSize);
			tableSize = tableSize<<1;			
			for(;i< tableSize;i++)
				itemList[i].value = "\0";
		}else{
			logE("symT: Not enough memory of symbolList!");
			return;
		}
	}
}
//-00-0-0-0-0-0-0-0-0-0-0--0---
//real symbol table is here!

int initSymbolTable(SymbolTable* table, char* name){
		table->tableName = name;
		table->length  = 0;
		table->size = ORIGINALSTSIZE;
		table->stItems = (SymbolTableItem*)malloc((table->size)*(sizeof(SymbolTableItem)));
}

int initSTGroup(){
	stGroup.length = 1;
	stGroup.size = 8;
	stGroup.stTables = (STGroup*)malloc((stGroup.size)*(sizeof(STGroup)));
	initSymbolTable(&stGroup.stTables[0], "all");
	stGroup.newTable = -1;
	stGroup.nowTable = 0;
}