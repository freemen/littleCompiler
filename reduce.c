#include "reduce.h"
//return how much we should pop
void VDEFTYPEIDIDSVFENHAO(){
	printf("VDEF => TYPE ID IDS VFENHAO\n");
}
void VDEFTYPEIDMLPARMRPARMLBBLOCKMRB(){
	printf("VDEF => TYPE ID MLPAR MRPAR MLB BLOCK MRB\n");
}
void VDEFTYPEIDMLPARPSMRPARMLBBLOCKMRB(){
	printf("VDEF => TYPE ID MLPAR PS MRPAR MLB BLOCK MRB\n");
}
void VFENHAOFENHAO(){
	printf("VFENHAO => FENHAO\n");
}
void MLBLB(){
	printf("MLB => LB\n");
}
void MRBRB(){
	printf("MRB => RB\n");
}
void TYPEINT(){
	printf("TYPE => INT\n");
}
void TYPECHAR(){
	printf("TYPE => CHAR\n");
}
void TYPEFLOAT(){
	printf("TYPE => FLOAT\n");
}
void IDPIDRID(){
	printf("ID => PID RID\n");
}
void PIDMULPID(){
	printf("PID => MUL PID\n");
}
void PID0000(){
	printf("PID => 0000\n");
}
void IDSMCOMMAIDIDS(){
	printf("IDS => MCOMMA ID IDS\n");
}
void MCOMMACOMMA(){
	printf("MCOMMA => COMMA\n");
}
void IDSLABINTEGERMRABIDS(){
	printf("IDS => LAB INTEGER MRAB IDS\n");
}
void IDS0000(){
	printf("IDS => 0000\n");
}
void MRABRAB(){
	printf("MRAB => RAB\n");
}
void PSPSMTYPEID(){
	printf("PS => PSM TYPE ID\n");
}
void PSPSPSNTYPEID(){
	printf("PS => PS PSN TYPE ID\n");
}
void PSM0000(){
	printf("PSM => 0000\n");
}
void PSNCOMMA(){
	printf("PSN => COMMA\n");
}
void STATEMENTVDEF(){
	printf("STATEMENT => VDEF\n");
}
void STATEMENTSTATEMENTSTATEMENTFILEEND(){
	printf("STATEMENT => STATEMENT STATEMENT FILEEND\n");
}
void STATEMENTBLOCK(){
	printf("STATEMENT => BLOCK\n");
}
void BLOCKLBSTATEMENTRB(){
	printf("BLOCK => LB STATEMENT RB\n");
}
void S2STATEMENT(){
	printf("S` => STATEMENT\n");
}

#define reducesize 26
reduceTableItem reduceTable[reducesize] = {{VDEF, 4,(void*)VDEFTYPEIDIDSVFENHAO},{VDEF, 7,(void*)VDEFTYPEIDMLPARMRPARMLBBLOCKMRB},{VDEF, 8,(void*)VDEFTYPEIDMLPARPSMRPARMLBBLOCKMRB},{VFENHAO, 1,(void*)VFENHAOFENHAO},{MLB, 1,(void*)MLBLB},{MRB, 1,(void*)MRBRB},{TYPE, 1,(void*)TYPEINT},{TYPE, 1,(void*)TYPECHAR},{TYPE, 1,(void*)TYPEFLOAT},{ID, 2,(void*)IDPIDRID},{PID, 2,(void*)PIDMULPID},{PID, 0,(void*)PID0000},{IDS, 3,(void*)IDSMCOMMAIDIDS},{MCOMMA, 1,(void*)MCOMMACOMMA},{IDS, 4,(void*)IDSLABINTEGERMRABIDS},{IDS, 0,(void*)IDS0000},{MRAB, 1,(void*)MRABRAB},{PS, 3,(void*)PSPSMTYPEID},{PS, 4,(void*)PSPSPSNTYPEID},{PSM, 0,(void*)PSM0000},{PSN, 1,(void*)PSNCOMMA},{S2, 1,(void*)S2STATEMENT},{STATEMENT, 1,(void*)STATEMENTVDEF},{STATEMENT, 3,(void*)STATEMENTSTATEMENTSTATEMENTFILEEND},{STATEMENT, 1,(void*)STATEMENTBLOCK},{BLOCK, 3,(void*)BLOCKLBSTATEMENTRB}};



int reduce(int which, int* left){
		(*left) = reduceTable[which].left;
		logIt("redu: in reduce %d:type= %d",which, reduceTable[which].left);
		reduceTable[which].fun();
		return reduceTable[which].rightNum;
}