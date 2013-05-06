#include "grammar.h"

void initGrammar(){
	//the tokens
	token = (Token*)malloc(sizeof(Token));
	token->value = NULL;
	logIt("gram: initGrammar finished");
}

void grammarProcess(){
	push(0);//I0;;//TODO:I0 should be a #define
	//first word(first legal lexical token)
	while( (wordLen=getNextWord(token)) < 0){		//if the lexical error occurs, omit it, just jump over it 
		logE("gram: lexical error!");
		printErrorInfo("main: some�ʷ�������Ϣshould be sent here");//TODO:
	}
	next = token->kind;
	
	while(1){
		iwantpause;
		if ((state = check(next, stack[top]/*state*/)) > 0){			//			shift();
			push(next);
			push(state);
			while( (wordLen=getNextWord(token)) < 0){
				logE("gram: lexical error!");
				printErrorInfo("main: some�ʷ�������Ϣshould be sent here");//TODO:
			}
			if (token->kind == FILEEND){
				logIt("gram: End");
			}else{
				logIt("gram: token<type:%d, address:%#x>",token->kind, token->value);
			}
			next = token->kind;
		}else if (state == acc){
			break;								//Accept and stop
		}else{														//			reduced();
			oldNext = next;
			pop(2*productionList[-state].rightNum);		//��ջ���ѹ�Լ���Ķ�����ջ�ﵯ��
			next = productionList[-state].leftEle;			//��Լ���Ǹ�����Ϊ�����������
			///reduced(-state);//����-stateҲ���ǹ�Լʽ�������Լ,
													//TODO:ִ�и������嶯��!!!
			if ( (state = check(next, stack[top])) == acc)		
				break;							//Accept and stop
			push(next);						//  shiftable
			push(state);
			next = oldNext;									//reuse the element that didn't be pushed before coz the reduction
		}
	}
	
}
/*
*return: 0 means accept, ������ʾ��Լ���ʽ��ţ�������ʾ��ת����״̬�ţ�
*/
int check(int next, int state){
	return 1;
}

int push(int element){
	return 0;	
}			

int pop(int element){
	return 0;
}