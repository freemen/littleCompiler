#include "public.h"

int addTokenValue(Token *token, int kind, char* word, int length){
	//free(token->value);			//free the original token value
	token->value = null;
			//TODO: and should be add to symbolTable??
			//TODO: so 下面的是乱写的
			token->kind = kind;
//			token->value = (char*)malloc((length+1)*sizeof(char));
			token->value = (char*)realloc(token->value,(length+1)*sizeof(char));
			if (!token->value) printf("\nbad!!\n");
			//and copy the new one to the value
			memcpy((char*)token->value, word, length+1);
			logIt("Token: token<%d, %s>", token->kind, (char*)token->value);
}