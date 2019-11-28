#include <stdio.h>
#include "StackOfDoublesModule.h"
#include <stdlib.h>
#include"Scanner.h"


#define PILA_VACIA_S -1
#define MAXBUFS 100

int sps = PILA_VACIA_S;
Tokentype pila[MAXBUFS];

const TokenType pops();
void pushs(const TokenType);
bool estavacias();
bool estaLlenas();
void operate(TokenType,const TokenValue);

int main(){

	Token token;
	TokenType tipoToken;
	TokenValue sustraendo,numerador;
	int aux=0;
		

	while((aux=getchar())){ 
		while(getNextToken(&token)){
			tipoToken=token.type;
			switch(tipoToken){
			case Number:
				const TokenType lastState = pops();
				if(lastState==Addition||lastState==Substraction||lastState==Division||lastState==Multiplication)
					push(operate(lastState,token.val);					
				else {
					printf("Se esperaba un operador\n");
					exit(0);
				}
				break;
			case LPARENS
			case PopResult:
				printf("El resultado es %f\n", pop());
				break;
			default:
				printf("something's gone wrong, terribly terribly wrong....");
				exit(0);
			}
		}
	}

void operate(TokenType operator,const TokenValue valor){

	select(operator){
		case Addition:
			push(pop()+valor);
			break;
		case Multiplication:
			push(pop()*valor);
			break;
		case Substraction:
			push(pop()-valor);
			break;
		case Division:
			if(valor!=0.0)
				push(pop()/valor);
			else
				printf("Division por cero!\n");
			break;
		default:
			printf("Operador no reconocido\n");
	}
}

const TokenType pops(){
	if(sps==PILA_VACIA_S){
		printf("no hay nada que popear\n");
		exit(0);
	}
	return pila[sps--];
}

void pushs(const TokenType elemento){
	if(sps==MAXBUFS-1){
		printf("no hay mas espacio en la pila\n");
		exit(0);
	}
	pila[++sps] = elemento;
}

bool estaVacias(){ return sps==PILA_VACIA; }

bool estaLlenas() { return sps==MAXBUF-1; }




	return 0;
}
