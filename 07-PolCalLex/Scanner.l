%{
#include"Scanner.h"
%}

%%

[*]				return Multiplication;
[/]				return Division;
[+]				return Addition;
[-]				return Substraction;
[1-9][0-9]*		return Number;
[\n]			return PopResult;
[ \t]			return ;
.				return LexError;

%%

int yywrap(void){
	return 1;
}
