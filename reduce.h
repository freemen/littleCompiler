//TODO:function is here



typedef struct reduceTableItem{
	char* left;								//��Լ���ķ��ս��
	int rightNum;							//��Լ�����
	void (*fun)();						//��Լ����
}reduceTableItem;

reduceTableItem reduceTable[];

