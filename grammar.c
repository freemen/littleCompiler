#include "grammar.h"

void initGrammar(){
	//the tokens
	token = (Token*)malloc(sizeof(Token));
	token->value = NULL;
	logIt("gram: initGrammar finished");
	syntop = -1;
}

void grammarProcess(){
	synpush(0);//I0;;//TODO:I0 should be a #define
	//first word(first legal lexical token)
	while( (wordLen=getNextWord(token)) < 0){		//if the lexical error occurs, omit it, just jump over it 
		logE("gram: lexical error!");
		printErrorInfo("main: some�ʷ�������Ϣshould be sent here");//TODO:
	}
	logIt("gram: token<type:%d, address:%#x>",token->kind, token->value);
	next = token->kind;
	
	while(1){
		iwantpause;
		if ((state = check(synStack[syntop]/*state*/, next)) > 0){			//			shift();
			synpush(next);
			synpush(state);
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
		}else if (state == accept){
			break;								//Accept and stop
		}else if(state == 0){
			logE("error!");
			break;
		}else{														//			reduced();
			oldNext = next;
			synpop(2*productionList[-state].rightNum);		//��ջ���ѹ�Լ���Ķ�����ջ�ﵯ��
			next = productionList[-state].leftEle;			//��Լ���Ǹ�����Ϊ�����������
			synpush(reduce(-state));//����-stateҲ���ǹ�Լʽ�������Լ,
													//TODO:ִ�и������嶯��!!!
			if (state = check(synStack[syntop], next) == accept)	
				break;							//Accept and stop
			synpush(next);						//  shiftable
			synpush(state);
			next = oldNext;									//reuse the element that didn't be pushed before coz the reduction
		}
	}
	
}
/*
*return: accept means accept, ������ʾ��Լ���ʽ��ţ�������ʾ��ת����״̬�ţ�
*/
int check(int state,int next){
	logIt("gram: check state:%d,symbol:%d %d",state, next,gotoTable[state][next-1]);
	return gotoTable[state][next-1];
}

int synpush(int element){
	synStack[syntop+1] = element;
	syntop++;
	
	int i = 0;
	logIt("gram: stack:");
	for (;i<=syntop; i++)
		printf("|%d",synStack[i]);
	logIt(" total:%d",i);
	
	if (syntop >= synsize-1)
		return 0;
	return 1;	
}			
//return if the element popped success
int synpop(int num){
	syntop -= num;
	
	int i = 0;
	logIt("gram: stack:");
	for (;i<=syntop; i++);
		printf("|%d",synStack[i]);
	logIt(" total:%d",i);
	
	if (syntop >=-1)
		return 1;
	else
		return 0;
}