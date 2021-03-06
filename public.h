#ifndef _PUBLIX_H
#define	_PUBLIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolDefine.h"
//#include "symbolTable.h"

//basic define
#define bool char
#define true 1
#define false 0
#define null NULL

#define iwantpause system("pause>nul")

char logText[128];

//////TOOLS
//stack


//handle when error occur
typedef struct Err{
	int errNum;
	int eLine;
}Err;
Err error;
void errorInit();
void logIt(const char* info, ...);
void logE(const char* info, ...);

void printErrorInfo(const char* info);

void errFinish();

//About the Token word
typedef struct Token{
	int kind;	
	//TODO: symbol table should be defined
	void* value;// 
}Token;
int addTokenValue(Token *token, int kind, char* word, int length);

//Add to the Symbol Table
void initSymbolT();
int add2SymbolT(Token *token, int length);
int checkAtKeyWordT(Token *token);

//in lexical (class)
bool initLexical(char* fileName);
int getNextWord(Token* token);

//in grammar
void initGrammar();
void grammarProcess();

#endif