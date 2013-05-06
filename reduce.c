#include "reduce.h"
//return how much we should pop
void VDEFTYPEIDIDSVFENHAO(){
	printf("VDEF => TYPE ID IDS VFENHAO");
}
void VDEFTYPEIDMLPARMRPARMLBBLOCKMRB(){
	printf("VDEF => TYPE ID MLPAR MRPAR MLB BLOCK MRB");
}
void VDEFTYPEIDMLPARPSMRPARMLBBLOCKMRB(){
	printf("VDEF => TYPE ID MLPAR PS MRPAR MLB BLOCK MRB");
}
void VFENHAOFENHAO(){
	printf("VFENHAO => FENHAO");
}
void MLBLB(){
	printf("MLB => LB");
}
void MRBRB(){
	printf("MRB => RB");
}
void TYPEINT(){
	printf("TYPE => INT");
}
void TYPECHAR(){
	printf("TYPE => CHAR");
}
void TYPEFLOAT(){
	printf("TYPE => FLOAT");
}
void IDPIDRID(){
	printf("ID => PID RID");
}
void PIDMULPID(){
	printf("PID => MUL PID");
}
void PID0000(){
	printf("PID => 0000");
}
void IDSMCOMMAIDIDS(){
	printf("IDS => MCOMMA ID IDS");
}
void MCOMMACOMMA(){
	printf("MCOMMA => COMMA");
}
void IDSLABINTEGERMRABIDS(){
	printf("IDS => LAB INTEGER MRAB IDS");
}
void IDS0000(){
	printf("IDS => 0000");
}
void MRABRAB(){
	printf("MRAB => RAB");
}
void PSPSMTYPEID(){
	printf("PS => PSM TYPE ID");
}
void PSPSPSNTYPEID(){
	printf("PS => PS PSN TYPE ID");
}
void PSM0000(){
	printf("PSM => 0000");
}
void PSNCOMMA(){
	printf("PSN => COMMA");
}
void STARTVDEF(){
	printf("START => VDEF");
}

#define reducesize 22
reduceTableItem reduceTable[reducesize] = {{VDEF, 4,(void*)VDEFTYPEIDIDSVFENHAO},{VDEF, 7,(void*)VDEFTYPEIDMLPARMRPARMLBBLOCKMRB},{VDEF, 8,(void*)VDEFTYPEIDMLPARPSMRPARMLBBLOCKMRB},{VFENHAO, 1,(void*)VFENHAOFENHAO},{MLB, 1,(void*)MLBLB},{MRB, 1,(void*)MRBRB},{TYPE, 1,(void*)TYPEINT},{TYPE, 1,(void*)TYPECHAR},{TYPE, 1,(void*)TYPEFLOAT},{ID, 2,(void*)IDPIDRID},{PID, 2,(void*)PIDMULPID},{PID, 1,(void*)PID0000},{IDS, 3,(void*)IDSMCOMMAIDIDS},{MCOMMA, 1,(void*)MCOMMACOMMA},{IDS, 4,(void*)IDSLABINTEGERMRABIDS},{IDS, 1,(void*)IDS0000},{MRAB, 1,(void*)MRABRAB},{PS, 3,(void*)PSPSMTYPEID},{PS, 4,(void*)PSPSPSNTYPEID},{PSM, 1,(void*)PSM0000},{PSN, 1,(void*)PSNCOMMA},{START, 1,(void*)STARTVDEF}};



int reduce(int which){
	int i=0;
	for(;i<reducesize;i++)
		if(reduceTable[i].left == which){
			logIt("redu: in reduce %d",i);
			reduceTable[i].fun();
			return;
		}
}