#ifndef _SYMBOLDEFINE_H
#define _SYMBOLDEFINE_H
//define the kind code

//key word
	//type
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
#define LPARENTHESES 80	//(
#define RPARENTHESES 81	//)

//segmentation
#define COMMA 90	//,
#define DOT 91	//.
#define SEMICOLON 92	//;
#define ARROW 93	//->
#define	EXCLAMATORY 96	//!

//blank
#define SPACE 110	//0x20 ' '
#define TAB 111	// '\t'
#define ENTER 112 // '\n'

//end
#define FILEEND 404


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