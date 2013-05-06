//TODO:functions are here
#include "public.h"


typedef struct reduceTableItem{
	int left;								//规约到的非终结符
	int rightNum;							//规约项个数
	void (*fun)();						//规约动作
}reduceTableItem;


int reduce(int which);