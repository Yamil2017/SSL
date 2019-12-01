#include<stdlib.h>
#include<stdio.h>
#include"StackOfCharsModule.h"

#define MAXBUF 100
#define PILA_VACIA -1
char buffer[MAXBUF];

int sp = 0;

char pop(){
	if(sp>0)
		return buffer[--sp];
	else {
		printf("error: pila vacia\n");
		return ' ';
	}
}

void push(char caracter){
	if(sp<MAXBUF)
		buffer[sp++]=caracter;
	else
		printf("error: pila llena, no se pudo pushear %c\n",caracter);	
}

bool isEmpty(){return (sp-1==PILA_VACIA)?true:false;}

bool isFull(){return (sp==MAXBUF)?true:false;}

