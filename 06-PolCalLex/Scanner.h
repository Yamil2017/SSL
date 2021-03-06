#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h>
#include <stdio.h>

enum TokenType{
	Number,
	Addition='+',
	Multiplication='*',
	Substraction='-',
	Division='/',
	PopResult='\n',
	LexError
};

typedef enum TokenType TokenType;

typedef double TokenValue;

typedef struct Token{
	TokenType type;
	TokenValue val;
} Token;

bool getNextToken(Token*,FILE*);
int getch(FILE*);
void ungetch(int);
TokenType getOperator(int);
//TokenValue getOperatorValue(int);

#endif
