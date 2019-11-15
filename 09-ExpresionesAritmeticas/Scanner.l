%{
#include"Scanner.h"
//#include<stdio.h>
%}

%%

[1-9][0-9]*		return NUMBER;
[0-9][.0-9]*		return NUMBER;
[(]			return LPARENS;
[)]			return RPARENS;
[\n]			return POPRESULT;
[ \t]			;
[+]			return ADDITION;
[-]			return SUBSTRACTION;
[*]			return MULTIPLICATION;
[/]			return DIVISION;
.			return LEXERROR;

%%

int yywrap(void){return 1;}

