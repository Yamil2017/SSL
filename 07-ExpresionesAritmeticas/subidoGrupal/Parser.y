%{
#include<stdio.h>
#include<stdlib.h>
extern int yylex();
void yyerror(char*);
%}

%union{double valor;}
%token <valor> NUMBER ADDITION SUBSTRACTION MULTIPLICATION DIVISION POPRESULT RPARENS LPARENS LEXERROR
%type <valor> E T F

%%

S : E POPRESULT				{printf("Resultado: %f\n",$1);}
  ;

E : E ADDITION T			{$$=$1+$3;}
  | E SUBSTRACTION T			{$$=$1-$3;}
  | T
  ;

T : T MULTIPLICATION F 			{$$=$1*$3;}
  | T DIVISION F 			{if($3==0)
						printf("Division por cero!\n");
					 else
						 $$=$1/$3;}
  | F					{$$=$1;}
  ; 

F : LPARENS E RPARENS			{$$=$2;}
  | '-' F				{$$=-$2;}
  | NUMBER				{$$=$1;}
  ;



%%

int main(){
	yyparse();
}

void yyerror(char* msg){
	fprintf(stderr,"%s\n",msg);
	exit(1);
}



