%{
#include<stdlib.h>
#include"y.tab.h"
%}

%%

[0-9]+([\.0-9]+)?([eE][0-9]+)?		{yylval.valor=atof(yytext); return NUMBER;}
[(]					return LPARENS;
[)]					return RPARENS;
[\n]					return POPRESULT;
[ \t]					;
[+]					return ADDITION;
[-]					return SUBSTRACTION;
[*]					return MULTIPLICATION;
[/]					return DIVISION;
.					return LEXERROR;

%%

int yywrap(void){return 1;}

