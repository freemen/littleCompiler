//TODO:functions are here
#include "public.h"


typedef struct reduceTableItem{
	int left;								//��Լ���ķ��ս��
	int rightNum;							//��Լ�����
	void (*fun)();						//��Լ����
}reduceTableItem;


int reduce(int which);