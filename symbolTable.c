#include "symbolTable.h"

SymbolTable sTable;

void initSymbolT(){
	tableSize = 128;
	itemList = (SymbolItem*)malloc(tableSize*(sizeof(SymbolItem)));
	pItem = 0;
}

int add2SymbolT(Token *token, LENGTHTODO){
	//TODO:����������ȥһ����ƥ�䣬�Ժ�ȷ��ű����֮����Ҫ���㷨
	int i=0;
	SymbolItem* it;
	for (i; i<pItem; i++){
		it = itemList[i];
		if (! strcmp((char*)token->value, it.value)){
			token->name = it.name;
			token->value = it.value;
			return i;
		}
	}
	it = itemList[pItem];
	it.name = token->name;
	it.value = (char*)malloc(sizeof(char)*
}