#include "public.h"

Token *token;			//token 
int wordLen;			//to receive the length of the token

int oldNext; 			//mark down the old "next" which haven't been push in the reduction
int next;					//point to the next element to push in stack

int state;				//the current state

#define acc 0
//the table is describe [elements to states]
//...
int gotoTable[10][10] = {};
int check(int next, int state);		//check how the action should be done from the state facing to this element,Shift out or Reduced\


//describe the production
struct{
	int leftEle;
	int rightNum;
} productionList[128];

//all kinds of stackTODO:not be the stack of int
int stack[256];
int top;
int push(int);
int pop(int);