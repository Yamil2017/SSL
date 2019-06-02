#ifndef LISTACONTIGUA_H
#define LISTACONTIGUA_H

typedef struct {
	int*arreglo;
	int tamanio;
}Nodo;

Nodo arregloDinamico(const int tamanio){
	Nodo lista;
	lista.arreglo=malloc(tamanio*sizeof(int));
	lista.tamanio=tamanio;
	return lista;
}

void set(Nodo lista,const int indice,const int valor){
	if(indice<lista.tamanio)
		lista.arreglo[indice]=valor;
	else
		perror("Indice fuera de limites\n");
}


#endif
