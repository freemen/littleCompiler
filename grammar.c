#include "grammar.h"

void initGrammar(){
	//the tokens
	token = (Token*)malloc(sizeof(Token));
	token->value = NULL;
	logIt("gram: initGrammar finished");
	//-------syn stack
	syntop = -1;
	//----semantic stack
	semsize = 256;
	semStack = (SemItem*)malloc(semsize*sizeof(SemItem));
	semtop = -1;
	//---other tools
	//tstop = -1; fstop =-1;
	lstop[true] = -1; lstop[false] = -1;

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
//				break;
			}else{
				logIt("gram: token<type:%d, address:%#x>",token->kind, token->value);
			}
			next = token->kind;
		}else if (state == accept){
			logIt("gram: ACCEPT!");
			break;								//Accept and stop
		}else if(state == 0){
			logE("error!");
			break;
		}else{														//			reduced();
			oldNext = next;
//			synpop(reducd(-state));		//��ջ���ѹ�Լ���Ķ�����ջ�ﵯ��
//			next = productionList[-state].leftEle;			//��Լ���Ǹ�����Ϊ�����������//���������Ǹ�reduce������
			synpop(2*reduce((-state-1), &next));//����-stateҲ���ǹ�Լʽ�������Լ,
			state = check(synStack[syntop], next);
			if (state == accept){	
				logIt("gram: ACCEPT!");
				break;							//Accept and stop
			}
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
	logIt("gram: check state:%d,symbol:%d is %d",state, next,gotoTable[state][next-1]);
	return gotoTable[state][next-1];
}
/////////syntax stack-----------------------------------
int synpush(int element){
	synStack[syntop+1] = element;
	syntop++;
	
	int i = 0;
	printf("gram: push stack:");
	for (;i<=syntop; i++)
		printf("|%d",synStack[i]);
	printf(" total:%d\n",i);
	
	if (syntop >= synsize-1)
		return 0;
	return syntop;	
}			
//return if the element popped success
int synpop(int num){
	syntop -= num;
	
	int i = 0;
	printf("gram: pop %d in stack:", num);
	for (;i<=syntop; i++)
		printf("|%d",synStack[i]);
	printf(" total:%d\n",i);
	
	if (syntop >=-1)
		return 1;
	else
		return 0;
}
//////////sematic stack--------------------------------
int sempush(SemItem element){
	semStack[semtop+1] = element;
	
	if(semtop >= semsize){
		semsize *= 2;
		SemItem* tem = semStack;
		semStack = (SemItem*)realloc(semStack,(semsize*sizeof(SemItem)));
		if (semStack)
			logIt("gram: the semStack's memory Reallocated in %#x",semsize);
		else
			logE("gram: Not Enough Memory for semStack!");
		memcpy(semStack, tem, _msize(tem));
	}
	return semtop++;
}
int sempop(){
	if(semtop<0)
		return 0;
	semtop--;
	return semtop;
}
///////other tools900000000000000000000000000000
//Slist struct
int addslist(Slist* slist,int* hole){
	int *l = &(slist->length);
	if ((*l)>=slistsize)
		return false;
	(*l)++;
	slist->list[(*l)] = hole;
	return true;
}
//Tstack and Fstack
int lspush(Slist slist, int TorF){
	lstack[TorF][lstop[TorF]] = slist;
	if (lstop[TorF] >= lssize)
		return false;
		return ++lstop[TorF];
}
int lspop(int TorF){
	if (lstop[TorF] < 0)
		return false;
	return --lstop[TorF];
}
int lscombine(Slist srcslist, int TorF){
	int i = 0;
	for (;i< srcslist.length;i++)
		if (addslist(&(lstack[TorF][lstop[TorF]].list), srcslist.list[i]) ==false)
			return false;
}
int backpatch(int address, int TorF){
	int i=0;
	Slist* sl = &(lstack[TorF][lstop[TorF]]);
	for(;i<sl->length;i++)
		(*sl->list[i]) = address;
}