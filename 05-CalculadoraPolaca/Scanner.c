#include<ctype.h>
#include"Scanner.h"
//#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50
//const int MAXSIZE = 50; //variably modified 's'/'buf' at file scope error
char s[MAXSIZE];
char buf[MAXSIZE];//buffer for ungetch
int bufp = 0;//next free position in buf

bool getNextToken (Token *t){
	int i,c;
	while((s[0]=c=getch())==' '||c=='\t')
		;
	if(!isdigit(c) && c!='.'){ //Not a number
		if(c==EOF)return false;
		t->val= c;
		t->type=getOperator(c);
		return true;
	}
	i=0;
	if(isdigit(c)){ //collect integer part
		while(isdigit(s[++i]=c=getch()))
			;
	}
	if(c=='.') //collect fraction part
		while(isdigit(s[++i]=c=getch()))
			;
	s[i]='\0';
	t->type=Number;
	t->val=atof(s);
	if(c!=EOF)
		ungetch(c);
	return true;
}

int getch(){
	return(bufp>0)?buf[--bufp]:getchar();
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
	default:
		printf("Unknown Operator: %c\n",op);
		return LexError;
	}
}


