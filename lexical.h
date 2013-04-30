#ifndef _LEXICAL_H
#define _LEXICAL_H
//ֻ����ʶ������¼���󣬲�������
#include "public.h"

//about the buffer pair
#define bufSize 1025
typedef char BUFFER[bufSize];
#define NRbuf bufSize-1
#define bufLast bufSize-1
//typedef struct BufferPair{
//	BUFFER first;
//	BUFFER second;
//}BufferPair;
//BufferPair buffers;
BUFFER buffers[2];
#define firstBuf buffers[0]
#define secondBuf buffers[1]
int whichBuffer;
int bufp;

FILE *file;
#define END -1

//the useful val
	char ch;
	int length;
	int wordSize;
	char* word;
	
int getAWord(Token* token);

bool readInBuffer();
void readNextLetter(char* ch);
int addToWord(char ch, char** word, int* wordSize, int length);

int saveAndNext();
int saveIt();
int addToken(Token* token, int kind);

int jumpOverError();

#endif