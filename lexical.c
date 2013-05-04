//#include <stdio.h>
#include "public.h"
#include "lexical.h"

//public (declared in public.h)
//return: weather initial sucessful or not
bool initLexical(char* fileName){
	firstBuf[bufLast] = END;
	secondBuf[bufLast] = END;
	if ((file = fopen(fileName, "r")) == null){
		logE("lexical: can't read");//TODO: print error
		return false;
	}else{
		fseek(file, SEEK_SET, 0);
		whichBuffer = 0;
		readInBuffer();
	
	}
	logIt("lexical: initial finished");
	return true;
}

//return the token with pointer in it
int getNextWord(Token* token){
	int length = getAWord(token);
	//TODO: find the place in the SymbleTable
	//TODO: mainly match the Id and the forbiden symble in the SymbleTable
	return length;	
}
	
//return: the length of the word
int getAWord(Token* token){
//	char ch;//Initialize
	length = 0;
	wordSize = 8;
	word = (char*)malloc(wordSize*sizeof(char));
		
	int i=0;
	for(i; i<wordSize; i++) word[i] = '\0';
		readNextLetter(&ch);
		//TODO:deal with the mass letters and words..
		//to read a complete word and jump over the blank
		while(ISEMPTY(ch)) readNextLetter(&ch);//read until it's not empty
//		if (ISLOWER(ch)){
//			//TODO many keyWord should be varified
//			switch(ch){
//				case 'i':		//maybe if or int
//					break;
//				case 'f':		//maybe for or float
//					break;
//				case 'c':		//maybe char
//					break;
//				case 's':		//maybe string
//					break;
//				case 'w':	//maybe while
//					break;
//				case 'e':		//maybe else
//					break;
//			}
//		}else if(ISUPPER(ch) || ISUNDERLINE(ch)){
//			while (ISWORD(ch)){
		if (ISLETTER(ch) || ISUNDERLINE(ch)){
			do{
					saveAndNext();
			}while(ISWORD(ch));//read a word over
			//TODO: add to token
				addToken(token, ID);
				add2SymbolT(token, length);	
			//bufp--;
		}else if (ISNZERO(ch)){
			do{
				saveAndNext();
			}while(ISDIGIT(ch));
			
				if (ISWORD(ch)){		//if is sth like 123abc
					jumpOverError();
				}else if (ch == '.') {//HERE:小数！
					do{
						saveAndNext();
					}while(ISDIGIT(ch));
					if (ISWORD(ch)){		//if is sth like 0.123abc
						jumpOverError();
					}else{							//success
						addToken(token, DECIMAL);
					}
				}else{							//success
					addToken(token, INTEGER);
				}
		}else if (ISZERO(ch)){					//0
			saveAndNext();
			if (ch == 'x' || ch == 'X'){	//0xFF0D
				do{
					saveAndNext();
				}while(ISHEX(ch));		//1234567890ABCDEFabcdef
				if (ISWORD(ch)){		//if is sth like 123abc
					jumpOverError();
				}else{							//success
					addToken(token, HEX);
				}
			}else if (ISDIGIT(ch)){		//0123 omit the zero
			}else if (ch == '.'){			//0.12 小数！HERE:deal with decimal
				do{
					saveAndNext();
				}while(ISDIGIT(ch));
				if (ISWORD(ch)){		//if is sth like 0.123abc
					jumpOverError();
				}else{							//success
					addToken(token, DECIMAL);
				}
			}else{						//0ead
				jumpOverError();
			}
		}else{				//not digit nor letter
			switch(ch){
				case '+':
					saveAndNext();
					if (ch == '+'){
						saveIt();
						addToken(token, SELFADD);
						break;
					}
					addToken(token, ADD);
					break;
				case '-':
					saveAndNext();
					if (ch == '-'){
						saveIt();
						addToken(token, SELFMINUS);
						break;
					}else if(ch == '>'){
						saveIt();
						addToken(token, ARROW);
						break;
					}
					addToken(token, MINUS);
					break;
				case ';':
					saveIt();
					addToken(token, SEMICOLON); 
					break;
				case '(':
					saveIt();
					addToken(token, LPARENTHESES); 
					break;
				case END:
					token->kind = FILEEND;
					token->value = null;
					//return length; 
					break;
				default:
					jumpOverError();
					break;
				}
		}
	//all switch will lead to here?
	//Deal with the end  --backward one letter
	free(word);
	bufp--;
	return length;
}




//private (declare only in lexical.h)

//operation of the buffer 
//return: whether read file successfully
bool readInBuffer(){
	int count = 0;			//count down the  number we real read
	bufp = 0;				//the pointer of the buffer should be put in the begining
	count = fread(buffers[whichBuffer], sizeof(char), NRbuf, file);
	
	if (count <0){
		logE("lexi: source code can't be readed");//TODO: these error should be handled by the errorHandle.c
		return false;
	}else if (count < NRbuf){//end
		buffers[whichBuffer][count] = END;
		buffers[whichBuffer][count+1] = '\0';
		logIt("lexi: readed %d in buffer\nlast several words: %s", count, buffers[whichBuffer]);
		//TODO::read successfully and over
		fclose(file);	
	}else{//count == NRbuf
		logIt("lexi: readed %d in buffer: %s", count, buffers[whichBuffer]);
		//TODO:when read succefully and can keep on reading next
		whichBuffer = 1- whichBuffer;// change 1 to 0 and 0 to 1
	}
	return true;
};
//and load the file in BufferPair when needed(call the function above)
void readNextLetter(char* ch){
	if (buffers[whichBuffer][bufp] == END){
		if (bufp == bufLast){
			readInBuffer();	
		}	
	}
	*ch = buffers[whichBuffer][bufp];
	if(*ch == ' ')
		logIt("lexi: a blank!");
	else if(*ch == '\t') 
		logIt("lexi: a tab!");
	else if (*ch == '\n'){
		logIt("lexi: begin a new line!");
		error.eLine ++;
	}else{
		//logIt("i read %dth letter %c", bufp, *ch);
	}
	bufp++;
}

//return the length of the word
int addToWord(char ch, char** word, int* wordSize, int length){
	if (length >= (*wordSize)){// make the word space larger
		(*wordSize)= (*wordSize)*2;
		char *tem = (*word);
		*word = (char*)realloc((*word), ((*wordSize)*sizeof(char)));
		if (*word)
			logIt("lexi: the word's memory Reallocated in %#x",*word);
		else
			logE("lexi: Not Enough Memory for word!");
		int i = length;
		for (i; i<(*wordSize); i++)	(*word)[i] = '\0';
		memcpy(*word, tem, strlen(tem));
	}
	//printf("length: %d, ch: %c", length, ch);
	(*word)[length-1] = ch;
//	logIt("now the word is %s", *word);
//	iwantpause;
}

int saveIt(){
	length++;
	addToWord(ch, &word, &wordSize, length);
	bufp++;
}

int saveAndNext(){
				length++;
				addToWord(ch, &word, &wordSize, length);
				readNextLetter(&ch);
}

int addToken(Token* token, int kind){
	addTokenValue(token, kind, word, length); 
}

int jumpOverError(){
					do{
						saveAndNext();
					}while(!ISEMPTY(ch) && ch != END);
					logE("I read a %s", word);
					length = -length;
					;	
}