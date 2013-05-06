//TODO:function is here



typedef struct reduceTableItem{
	char* left;								//规约到的非终结符
	int rightNum;							//规约项个数
	void (*fun)();						//规约动作
}reduceTableItem;

reduceTableItem reduceTable[];

