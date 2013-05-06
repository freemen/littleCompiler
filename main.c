//#include <stdio.h>
#include "public.h"

const char* defaultFile = "pig.freemen";

int main(int argc, char *argv[]){
	{//initial
	bool success = true;
	initSymbolT();
	errorInit();
	if (argc < 2)
		success = initLexical(defaultFile);
	else
		success =initLexical(argv[1]);
	if (success == false)
		return -1;
	}	
	initGrammar();
	
	grammarProcess();
	
	//finish
	errFinish();
	return 0;
}