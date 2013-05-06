#include "public.h"
typedef struct StackEx{				//a stack that is a array indeed but can be expend the length
	void *items;	
	int top;
	int length;
	int size;
}StackEx;

void* top(StackEx* stack){				//return the top item in the stack
	return &((*stack).items[top]);
}

StackEx* newStack(void *itemType){			//create a stack for the type of item in the paramxxx
	
}
//damn it .FAIL