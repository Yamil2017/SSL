#ifndef LISTAENLAZADDA_H
#define LISTAENLAZADA_H

typedef struct* {
	Nodo* siguiente;
	int tamanio;
}Nodo;

void  Lista(const int tamanio,Nodo &lista){
	lista->siguiente=NULL;
	lista->tamanio = tamanio;
}

Nodo& set(Nodo& lista,const int valor,const int indice){
	Nodo* aux=malloc(sizeof(Nodo));
	aux->siguiente=NULL;
	aux->tamanio=lista->tamanio;
	lista->siguiente=aux;
	lista=aux;
	return lista;
}


#endif
