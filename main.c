//#include <stdio.h>
#include "public.h"

const char* defaultFile = "pig.freemen";

int main(int argc, char *argv[]){
	//initial
	bool success = true;
	initSymbolT();
	errorInit();
	if (argc < 2)
		success = initLexical(defaultFile);
	else
		success =initLexical(argv[1]);
	if (success == false)
		return -1;
		
	//the tokens
	Token* token = (Token*)malloc(sizeof(Token));
	token->value = NULL;
	int wordLen;
	
	do{
		if( (wordLen=getNextWord(token)) < 0){
			logE("lexical error!");
			printErrorInfo("some´Ê·¨´íÎóÐÅÏ¢should be sent here");//TODO:
			continue;
		}
		if (token->kind == FILEEND){
			logIt("End");
			break;
		}
		//TODO: syntactic analyse and other work
		logIt("token<type:%d, address:%#x>",token->kind, token->value);
		iwantpause;
	}while(1);
	
	//finish
	errFinish();
	return 0;
}