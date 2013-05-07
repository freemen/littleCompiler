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
	sempop();
	printf("VFENHAO => FENHAO\n");
}
void MLPARLPAR(){
	//stGroup.stTables[stGroup.nowTable].stItems
	printf("MLPAR => LPAR\n");
}
void MRPARRPAR(){
	printf("MRPAR => RPAR\n");
}
void MLB0000(){
	printf("MLB => 0000\n");
}
void MRB0000(){
	printf("MRB => 0000\n");
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
void FINDIDRID(){
	printf("FINDID => RID\n");
}
void AMMD(){
	printf("AM => MD\n");
}
void AMAMADDMD(){
	printf("AM => AM ADD MD\n");
}
void AMAMMINUSMD(){
	printf("AM => AM MINUS MD\n");
}
void MDSELF(){
	printf("MD => SELF\n");
}
void MDMDMULSELF(){
	printf("MD => MD MUL SELF\n");
}
void MDMDDIVSELF(){
	printf("MD => MD DIV SELF\n");
}
void SELFMINUSSELF(){
	printf("SELF => MINUS SELF\n");
}
void SELFLPARAMRPAR(){
	printf("SELF => LPAR AM RPAR\n");
}
void SELFFINDID(){
	printf("SELF => FINDID\n");
}
void SELFINTEGER(){
	printf("SELF => INTEGER\n");
}
void ASSIGNFINDIDEQUAMFENHAO(){
	printf("ASSIGN => FINDID EQU AM FENHAO\n");
}
void BOOL1BOOL1BORMBORBOOL2(){
	printf("BOOL1 => BOOL1 BOR MBOR BOOL2\n");
}
void MBOR0000(){
	printf("MBOR => 0000\n");
}
void BOOL1BOOL2(){
	printf("BOOL1 => BOOL2\n");
}
void BOOL2BOOL2BANDMBANDBOOL3(){
	printf("BOOL2 => BOOL2 BAND MBAND BOOL3\n");
}
void MBAND0000(){
	printf("MBAND => 0000\n");
}
void BOOL2BOOL3(){
	printf("BOOL2 => BOOL3\n");
}
void BOOL3BNOTBOOL3(){
	printf("BOOL3 => BNOT BOOL3\n");
}
void BOOL3LPARBOOL1RPAR(){
	printf("BOOL3 => LPAR BOOL1 RPAR\n");
}
void BOOL3TRUE(){
	printf("BOOL3 => TRUE\n");
}
void BOOL3FALSE(){
	printf("BOOL3 => FALSE\n");
}
void BOOL3AMRELOPAM(){
	printf("BOOL3 => AM RELOP AM\n");
}
void RELOPGE(){
	printf("RELOP => GE\n");
}
void RELOPGT(){
	printf("RELOP => GT\n");
}
void RELOPLE(){
	printf("RELOP => LE\n");
}
void RELOPLT(){
	printf("RELOP => LT\n");
}
void RELOPEQ(){
	printf("RELOP => EQ\n");
}
void RELOPUEQ(){
	printf("RELOP => UEQ\n");
}
void CONTROLIFBOOL1MIFTRUEBLOCKMIFFALSEMIFEND(){
	printf("CONTROL => IF BOOL1 MIFTRUE BLOCK MIFFALSE MIFEND\n");
}
void CONTROLIFBOOL1MIFTRUEBLOCKMIFFALSEELSEBLOCKMIFEND(){
	printf("CONTROL => IF BOOL1 MIFTRUE BLOCK MIFFALSE ELSE BLOCK MIFEND\n");
}
void MIFTRUE0000(){
	printf("MIFTRUE => 0000\n");
}
void MIFFALSE0000(){
	printf("MIFFALSE => 0000\n");
}
void MIFEND0000(){
	printf("MIFEND => 0000\n");
}
void CONTROLWHILEMLWHILEBOOL1MIFTRUEBLOCKMWHILEEND(){
	printf("CONTROL => WHILE MLWHILE BOOL1 MIFTRUE BLOCK MWHILEEND\n");
}
void MWHILEEND0000(){
	printf("MWHILEEND => 0000\n");
}
void MLWHILE0000(){
	printf("MLWHILE => 0000\n");
}
void STATEMENTVDEF(){
	printf("STATEMENT => VDEF\n");
}
void STATEMENTASSIGN(){
	printf("STATEMENT => ASSIGN\n");
}
void STATEMENTCONTROL(){
	printf("STATEMENT => CONTROL\n");
}
void STATEMENTSSTATEMENTSTATEMENTS(){
	printf("STATEMENTS => STATEMENT STATEMENTS\n");
}
void STATEMENTS0000(){
	printf("STATEMENTS => 0000\n");
}
void STATEMENTBLOCK(){
	printf("STATEMENT => BLOCK\n");
}
void BLOCKLBSTATEMENTSRB(){
	printf("BLOCK => LB STATEMENTS RB\n");
}
void S72STATEMENTS(){
	printf("S72 => STATEMENTS\n");
}

#define reducesize 68
reduceTableItem reduceTable[reducesize] = {{VDEF, 4,(void*)VDEFTYPEIDIDSVFENHAO},{VDEF, 7,(void*)VDEFTYPEIDMLPARMRPARMLBBLOCKMRB},{VDEF, 8,(void*)VDEFTYPEIDMLPARPSMRPARMLBBLOCKMRB},{VFENHAO, 1,(void*)VFENHAOFENHAO},{MLPAR, 1,(void*)MLPARLPAR},{MRPAR, 1,(void*)MRPARRPAR},{MLB, 0,(void*)MLB0000},{MRB, 0,(void*)MRB0000},{TYPE, 1,(void*)TYPEINT},{TYPE, 1,(void*)TYPECHAR},{TYPE, 1,(void*)TYPEFLOAT},{ID, 2,(void*)IDPIDRID},{PID, 2,(void*)PIDMULPID},{PID, 0,(void*)PID0000},{IDS, 3,(void*)IDSMCOMMAIDIDS},{MCOMMA, 1,(void*)MCOMMACOMMA},{IDS, 4,(void*)IDSLABINTEGERMRABIDS},{IDS, 0,(void*)IDS0000},{MRAB, 1,(void*)MRABRAB},{PS, 3,(void*)PSPSMTYPEID},{PS, 4,(void*)PSPSPSNTYPEID},{PSM, 0,(void*)PSM0000},{PSN, 1,(void*)PSNCOMMA},{FINDID, 1,(void*)FINDIDRID},{AM, 1,(void*)AMMD},{AM, 3,(void*)AMAMADDMD},{AM, 3,(void*)AMAMMINUSMD},{MD, 1,(void*)MDSELF},{MD, 3,(void*)MDMDMULSELF},{MD, 3,(void*)MDMDDIVSELF},{SELF, 2,(void*)SELFMINUSSELF},{SELF, 3,(void*)SELFLPARAMRPAR},{SELF, 1,(void*)SELFFINDID},{SELF, 1,(void*)SELFINTEGER},{ASSIGN, 4,(void*)ASSIGNFINDIDEQUAMFENHAO},{BOOL1, 4,(void*)BOOL1BOOL1BORMBORBOOL2},{MBOR, 0,(void*)MBOR0000},{BOOL1, 1,(void*)BOOL1BOOL2},{BOOL2, 4,(void*)BOOL2BOOL2BANDMBANDBOOL3},{MBAND, 0,(void*)MBAND0000},{BOOL2, 1,(void*)BOOL2BOOL3},{BOOL3, 2,(void*)BOOL3BNOTBOOL3},{BOOL3, 3,(void*)BOOL3LPARBOOL1RPAR},{BOOL3, 1,(void*)BOOL3TRUE},{BOOL3, 1,(void*)BOOL3FALSE},{BOOL3, 3,(void*)BOOL3AMRELOPAM},{RELOP, 1,(void*)RELOPGE},{RELOP, 1,(void*)RELOPGT},{RELOP, 1,(void*)RELOPLE},{RELOP, 1,(void*)RELOPLT},{RELOP, 1,(void*)RELOPEQ},{RELOP, 1,(void*)RELOPUEQ},{CONTROL, 6,(void*)CONTROLIFBOOL1MIFTRUEBLOCKMIFFALSEMIFEND},{CONTROL, 8,(void*)CONTROLIFBOOL1MIFTRUEBLOCKMIFFALSEELSEBLOCKMIFEND},{MIFTRUE, 0,(void*)MIFTRUE0000},{MIFFALSE, 0,(void*)MIFFALSE0000},{MIFEND, 0,(void*)MIFEND0000},{CONTROL, 6,(void*)CONTROLWHILEMLWHILEBOOL1MIFTRUEBLOCKMWHILEEND},{MWHILEEND, 0,(void*)MWHILEEND0000},{MLWHILE, 0,(void*)MLWHILE0000},{STATEMENT, 1,(void*)STATEMENTVDEF},{STATEMENT, 1,(void*)STATEMENTASSIGN},{STATEMENT, 1,(void*)STATEMENTCONTROL},{STATEMENTS, 2,(void*)STATEMENTSSTATEMENTSTATEMENTS},{STATEMENTS, 0,(void*)STATEMENTS0000},{STATEMENT, 1,(void*)STATEMENTBLOCK},{BLOCK, 3,(void*)BLOCKLBSTATEMENTSRB},{S72, 1,(void*)S72STATEMENTS}};



int reduce(int which, int* left){
		(*left) = reduceTable[which].left;
		logIt("redu: in reduce %d:type= %d",which, reduceTable[which].left);
		reduceTable[which].fun();
		return reduceTable[which].rightNum;
}