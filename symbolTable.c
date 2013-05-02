#include "symbolTable.h"

SymbolTable sTable;

void initSymbolT(){
	tableSize = 128;
	itemList = (SymbolItem*)malloc(tableSize*(sizeof(SymbolItem)));
	memcpy(itemList, keyWord, sizeof(keyWord));
	iNum = 0;
}

int add2SymbolT(Token *token, int length){
	//TODO:����������ȥһ����ƥ�䣬�Ժ�ȷ��ű����֮����Ҫ���㷨
	int i=0;
	SymbolItem* it;
	for (i; i<iNum; i++){
		it = itemList[i];
		if (! strcmp((char*)token->value, it.value)){
			token->name = it.name;
			token->value = it.value;
			return i;					//����ҵ��ˣ���ʹ�÷��ű����һ��
		}
	}
	it = itemList[iNum];
	it.name = token->name;
	it.value = (char*)malloc(sizeof(char)*(length+1));
	strcpy(it.value, token->value, strlen(token->value)+1);
	oneMoreSymbol();
	return i;							//�Ҳ������½�
}
/*
*		let the item number in Symbol table increace
*/
void oneMoreSymbol(){
	iNum++;
	if (iNum >= tableSize){	//���������飬�������޲���ֱ�Ӽӣ�ֻ�ܶ�̬����
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