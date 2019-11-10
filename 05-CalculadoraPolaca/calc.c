#include <stdio.h>
#include "StackOfDoublesModule.h"
#include <stdlib.h>
#include <time.h> //para prueba de pila
#include"Scanner.h"

int main(){
	FILE* archivo = fopen("expresiones","r");
	Token token;
	TokenType tipoToken;
	TokenValue sustraendo,numerador;
	int aux=0;

	while((aux=getch(archivo))!=EOF){ //&& aux!='\n'){
		ungetch(aux);
		while(getNextToken(&token,archivo)){
			tipoToken=token.type;
			switch(tipoToken){
			case Number:
				push(token.val);
				break;
			case Addition:
				push(pop()+pop());
				break;
			case Multiplication:
				push(pop()*pop());
				break;
			case Substraction:
				sustraendo = pop();
				push(pop()-sustraendo);
				break;
			case Division:
				numerador = pop();
				if(numerador!=0.0)
					push(pop()/numerador);
				else
					printf("Division por cero!\n");
				break;
			case PopResult:
				printf("El resultado es %f\n", pop());
				break;
			default:
				printf("something's gone wrong, terribly terribly wrong....");
				exit(0);
			}
		}
	}
	//printf("the result of the expression is = %f\n",pop());

	/* prueba de la pila
	srand(time(0));
	for (int i=0; i<30;i++){
		double var = (double)(rand()%10);
		printf("el valor pusheado es %g\n",var);
		push(var);
	}
	for (int i=0;i<33;i++)
		printf("el valor popeado es: %g\n",pop());
	*/
	return 0;
}
