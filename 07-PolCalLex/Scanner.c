#include"Scanner.h"
#include<ctype.h>
#include<stdlib.h>
#define MAXSIZE 50

extern int yylex();
//extern int yylineno;
extern char* yytext;
extern FILE* yyin;
//const int MAXSIZE = 50; //variably modified 's'/'buf' at file scope error
char s[MAXSIZE];
char buf[MAXSIZE];//buffer for ungetch
int bufp = 0;//next free position in buf

bool getNextToken (Token *t,FILE* archivo){
	yyin = archivo;
	int ntoken=yylex();

	if(ntoken){
		t->type=ntoken;
		t->val=atof(yytext);
		return true;
	}
	else
		return false;
}

int getch(FILE* archivo){
	return(bufp>0)?buf[--bufp]:getc(archivo);//getchar();
}

void ungetch(int c){
	if(bufp>=MAXSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]=c;
}

TokenType getOperator(int op){
	switch(op){
	case '+':
		return Addition;
		break;
	case '-':
		return Substraction;
		break;
	case '*':
		return Multiplication;
		break;
	case '/':
		return Division;
		break;
	case '\n':
		return PopResult;
		break;
	default:
		printf("Unknown Operator: %c\n",op);
		return LexError;
	}
}


