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
#define MUL 10
#define COMMA 11
#define LAB 12
#define RAB 13
#define INTEGER 14
#define DECIMAL 15
#define HEX 16
#define SELFADD 17
#define ADD 18
#define SELFMINUS 19
#define MINUS 20
#define ARROW 21
#define EQU 22
#define DIV 23
#define BOR 24
#define BAND 25
#define BNOT 26
#define TRUE 27
#define FALSE 28
#define GE 29
#define GT 30
#define LE 31
#define LT 32
#define EQ 33
#define UEQ 34
#define IF 35
#define ELSE 36
#define WHILE 37
#define FILEEND 38

#define STATEMENT 39
#define STATEMENTS 40
#define VDEF 41
#define TYPE 42
#define ID 43
#define IDS 44
#define VFENHAO 45
#define MLPAR 46
#define MRPAR 47
#define MLB 48
#define BLOCK 49
#define MRB 50
#define PS 51
#define PID 52
#define MCOMMA 53
#define MRAB 54
#define PSM 55
#define PSN 56
#define FINDID 57
#define AM 58
#define MD 59
#define SELF 60
#define ASSIGN 61
#define BOOL1 62
#define BOOL2 63
#define BOOL3 64
#define MBOR 65
#define MBAND 66
#define RELOP 67
#define MIFTRUE 68
#define MIFFALSE 69
#define MIFEND 70
#define CONTROL 71
#define MLWHILE 72
#define MWHILEEND 73

#define S72 1234
#define IDONTKNOW 2345
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