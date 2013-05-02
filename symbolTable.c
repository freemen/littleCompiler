#include "symbolTable.h"

SymbolTable sTable;

void initSymbolT(){
	tableSize = 128;
	itemList = (SymbolItem*)malloc(tableSize*(sizeof(SymbolItem)));
	memcpy(itemList, keyWord, sizeof(keyWord));
	iNum = 0;
}

int add2SymbolT(Token *token, int length){
	//TODO:现在是塞进去一个个匹配，以后等符号表变了之后，再要改算法
	int i=0;
	SymbolItem* it;
	for (i; i<iNum; i++){
		it = itemList[i];
		if (! strcmp((char*)token->value, it.value)){
			token->name = it.name;
			token->value = it.value;
			return i;					//如果找到了，就使用符号表的这一个
		}
	}
	it = itemList[iNum];
	it.name = token->name;
	it.value = (char*)malloc(sizeof(char)*(length+1));
	strcpy(it.value, token->value, strlen(token->value)+1);
	oneMoreSymbol();
	return i;							//找不到就新建
}
/*
*		let the item number in Symbol table increace
*/
void oneMoreSymbol(){
	iNum++;
	if (iNum >= tableSize){	//现在是数组，长度有限不能直接加，只能动态增长
		SymbolItem* tem = itemList;
		itemList = (SymbolItem*)realloc(itemList, sizeof(SymbolItem)*(tableSize<<1));
		if(itemList)
			logIt("the symbolList is reallocated");
		else{
			logE("Not enough memory of symbolList!");
			return;
		}
		memcpy(itemList, tem, tableSize);
		tableSize = tableSize<<1;			
	}
}