#include <stdio.h>
#include "StackOfDoublesModule.h"
#include <stdlib.h>
#include <time.h> //para prueba de pila
#include"Scanner.h"

int main(){
	Token token;
	TokenType tipoToken;
	TokenValue minuendo,denominador;
	int aux;
	while((aux=getch())!=EOF && aux!='\n'){
		ungetch(aux);
		while(getNextToken(&token)){
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
				minuendo = pop();
				push(minuendo-pop());
				break;
			case Division:
				denominador = pop();
				push(denominador/pop());
				break;
			default:
				printf("something's gone wrong, terribly terribly wrong....");
			}
		}
	}
	printf("the result of the expression is = %f\n",pop());

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
