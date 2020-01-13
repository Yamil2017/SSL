#include"Scanner.h"
#include<ctype.h>
#include<stdlib.h>
#define MAXSIZE 50

//const int MAXSIZE = 50; //variably modified 's'/'buf' at file scope error
char s[MAXSIZE];
char buf[MAXSIZE];//buffer for ungetch
int bufp = 0;//next free position in buf


bool getNextToken (Token *t){
	int i,lexeme;
	while((s[0]=lexeme=getch())==' '||lexeme=='\t')
		;
	if(!isdigit(lexeme) && lexeme!='.'){ //Not a number
		if(lexeme=='+'||lexeme=='/'||lexeme=='-'||lexeme=='*'){
			t->val= lexeme;
			t->type=getOperator(lexeme);
			return true;
		}
		else {
			printf("caracter no reconocido\n");
			return false;
		}
	}
	i=0;
	if(isdigit(lexeme)){ //collect integer part
		while(isdigit(s[++i]=lexeme=getch()))
			;
	}
	if(lexeme=='.') //collect fraction part
		while(isdigit(s[++i]=lexeme=getch()))
			;
	s[i]='\0';
	t->type=Number;
	t->val=atof(s);
	if(lexeme!=EOF)
		ungetch(lexeme);
	return true;
}

int getch(){
	return (bufp>0)?buf[--bufp]:getchar();
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


