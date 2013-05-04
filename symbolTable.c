#include "symbolTable.h"

SymbolTable sTable;

void initSymbolT(){
	tableSize = 128;
	itemList = (SymbolItem*)malloc(tableSize*(sizeof(SymbolItem)));
	
	iNum = sizeof(keyWord) >> 3;			//the sizeof(symbolItem) is 8
	memcpy(itemList, keyWord, sizeof(keyWord));
	int i=iNum;
	for(;i<tableSize;i++)
		itemList[i].value = "\0";
	logIt("symbolTable: initial %d symbol",iNum);
}
/*
*input: token: is the one which just be recognised
*					token->value is the word with '\0' in the end
*				lenght: is the real character amount in the word, without '\0'
*output: the index of this token in SymbolTable
*/
int add2SymbolT(Token *token, int length){
	//TODO:现在是塞进去一个个匹配，以后等符号表变了之后，再要改算法
	int i=0;
	SymbolItem it;
	for (i; i<iNum; i++){
		it = itemList[i];
		if (! strcmp((char*)token->value, it.value)){
			token->kind = it.name;
			token->value = it.value;
			logIt("symT: find %s in symbolList[%d]!",(char*)token->value,i);
			return i;					//如果找到了，就使用符号表的这一个
		}
	}
	it = itemList[iNum];
	it.name = token->kind;
	it.value = (char*)malloc(sizeof(char)*(length+1));
	memcpy(it.value, token->value, (strlen(token->value)+1));
	logIt("symT: add a %s in symbolList[%d]",it.value,i);
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