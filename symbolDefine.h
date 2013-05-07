#ifndef _SYMBOLDEFINE_H
#define _SYMBOLDEFINE_H
//define the kind code
#define FENHAO 1
#define LPAR 2
#define RPAR 3
#define LB 4
#define RB 5
#define INT 6
#define CHAR 7
#define FLOAT 8
#define RID 9
#define FILEEND 10
#define MUL 11
#define COMMA 12
#define LAB 13
#define RAB 14
#define INTEGER 15
#define DECIMAL 16
#define HEX 17
#define SELFADD 18
#define ADD 19
#define SELFMINUS 20
#define MINUS 21
#define ARROW 22
#define IDONTKNOW 23

#define STATEMENT 24
#define VDEF 25
#define TYPE 26
#define ID 27
#define IDS 28
#define VFENHAO 29
#define MLPAR 30
#define MRPAR 31
#define MLB 32
#define BLOCK 33
#define MRB 34
#define PS 35
#define PID 36
#define MCOMMA 37
#define MRAB 38
#define PSM 39
#define PSN 40

#define S2 1234
//end
//#define FILEEND 404
//key word
/*	//type
#define INT 1
#define CHAR 2
#define FLOAT 3
#define STRING 4
#define FREEMEN -5
#define STACK -6
#define HEAP -7
#define TREE -8
	//construct word
#define WHILE 15
#define FOR 16
#define IF 17
#define ELSE 18
#define THEN -19//should i use it?
#define STRUCT -20
#define FUNCTION -21

//variable
#define ID 30
#define INTEGER 31	//整数
#define DECIMAL 32	//带小数
#define CHARACTER 33	//单个字符
#define CSTRING 34	//字符串
#define COLOR -35
#define HEX 37			//0xFF0A

//some symbol
	//operator
#define ADD 45	//+
#define MINUS 46	//-
#define MULTIPLY 47	//*

#define VOLUATION 50 //赋值=

#define SELFADD 52 //++
#define SELFMINUS 53//--
	//judge operator
#define GREATER 60	//>
#define GREATEREQ 61	//>=

#define EQUAL 79	//==
	//delimiter
		//These are Parentheses, Square brackets, Angle brackets and Brace.	
		//括号有小括号、中括号、角括号和大括号。
#define LPAR 80	//(
#define RPARS 81	//)

//segmentation
#define COMMA 90	//,
#define DOT 91	//.
#define SEMICOLON 92	//;
#define ARROW 93	//->
#define	EXCLAMATORY 96	//!

//blank
#define SPACE 110	//0x20 ' '
#define TAB 111	// '\t'
#define ENTER 112 // '\n'*/



#define ISUPPER(x) (x<=0x5A && x>=0x41)
#define ISLOWER(x) (x<=0x7A && x>=0x61)
#define ISLETTER(x) (ISLOWER(x) || ISUPPER(x))
#define ISNZERO(x) (x <= '9' && x>='1')
#define ISZERO(x) (x == '0')
#define ISDIGIT(x) (x<=0x39 && x>= 0x30)
#define ISUNDERLINE(x) (x == '_')
#define ISWORD(x) (ISUPPER(x) || ISLOWER(x) || ISDIGIT(x) || ISUNDERLINE(x) )
#define ISNEMPTY(x) (x!= 0x20)
#define ISEMPTY(ch) (ch == ' ' || ch == '\n' || ch == '\t')
#define ISHEX(x) ((x <= 'f' && x >= 'a')||(x<='F' && x>='A')||(ISDIGIT(x)))

#endif