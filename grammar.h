#include "public.h"

Token *token;			//token 
int wordLen;			//to receive the length of the token

int oldNext; 			//mark down the old "next" which haven't been push in the reduction
int next;					//point to the next element to push in stack

int state;				//the current state

//the table is describe [elements to states]
//...
#define acc 0
int check(int next, int state);		//check how the action should be done from the state facing to this element,Shift out or Reduced\


//describe the production
struct{
	int leftEle;
	int rightNum;
} productionList[128];

//all kinds of stack
int stack[256];
int top;
int push(int);
int pop(int);