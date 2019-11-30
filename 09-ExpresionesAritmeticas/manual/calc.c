#include <stdio.h>
#include "StackOfDoublesModule.h"
#include <stdlib.h>
#include"Scanner.h"


#define PILA_VACIA_S -1
#define MAXBUFS 100

int sps = PILA_VACIA_S;
TokenType pila[MAXBUFS];

TokenType pops();
void pushs(const TokenType);
bool estaVacias();
bool estaLlenas();
void operate(TokenType,const TokenValue);

int main(){

	Token token;
	TokenType tipoToken;
	TokenValue sustraendo,numerador;
	int aux=0;
	TokenType lastState;
	TokenType beforeLastState;

	while(getNextToken(&token)){
		tipoToken=token.type;
		switch(tipoToken){
		case Number:
			if(!estaVacias()){
				lastState = pops();
				if(lastState==Addition||lastState==Substraction||lastState==Division||lastState==Multiplication){
					beforeLastState = pops();
					if(beforeLastState==Number){
						operate(lastState,token.val);
						pushs(Number);
					}
					else{
						pushs(beforeLastState);
						pushs(lastState);
						pushs(Number);
						push(token.val);
					}
				}
				else if(lastState==Lparens){
					pushs(lastState);
					push(token.val);
				}	
				else {
					printf("Se esperaba un operador\n");
					exit(0);
				}
			}
			else{
				pushs(tipoToken);
				push(token.val);
			}	
			break;
		case Lparens:case Addition:case Multiplication:case Division:case Substraction:
			pushs(tipoToken);
			break;
		case Rparens:
			lastState=pops();
			if(lastState==Number){
				pops();
				pushs(lastState);
			}else{
				printf("Error sintactico\n");
				exit(0);
			}	
			break;
		case PopResult:
			printf("El resultado es %f\n", pop());
			break;
		default:
			printf("something's gone wrong, terribly terribly wrong....");
			exit(0);
		}
	}

	return 0;
}

void operate(TokenType operator,const TokenValue valor){

	switch(operator){
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

TokenType pops(){
	if(sps==PILA_VACIA_S){
		printf("no hay estado que popear\n");
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

bool estaVacias(){ return sps==PILA_VACIA_S; }

bool estaLlenas() { return sps==MAXBUFS-1; }

