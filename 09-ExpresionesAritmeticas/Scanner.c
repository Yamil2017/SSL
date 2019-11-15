#include<stdio.h>
#include"Scanner.h"


int main(){

extern int yylex();
extern char* yytext;
extern int yylineno;

int token;
while(yylex()!=EOF)
	printf("El token leido es %s\n",yytext);

return 0;
}
