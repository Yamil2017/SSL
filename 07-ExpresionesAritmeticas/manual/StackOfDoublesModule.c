#include <stdio.h>
#include "StackOfDoublesModule.h"
#include <stdlib.h>

#define PILA_VACIA -1
#define MAXBUF 100

static int sp = PILA_VACIA;
static ItemPila pila[MAXBUF];

const ItemPila pop(){
	if(sp==PILA_VACIA){
		printf("no hay nada que popear\n");
		exit(0);
	}
	return pila[sp--];
}

void push(const ItemPila elemento){
	if(sp==MAXBUF-1){
		printf("no hay mas espacio en la pila\n");
		exit(0);
	}
	pila[++sp] = elemento;
}

bool estaVacia(){ return sp==PILA_VACIA; }

bool estaLlena() { return sp==MAXBUF-1; }
