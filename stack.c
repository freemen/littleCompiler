#include "public.h"
typedef struct StackEx{				//a stack that is a array indeed but can be expend the length
	void **stack;	
	int top;
	int length;
	int size;
}StackEx;

void* top(void **stack){
	return (*stack)[top];
}