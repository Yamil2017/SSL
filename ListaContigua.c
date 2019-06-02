#include<stdlib.h>
#include"ListaContigua.h"


int main(){
	
	Nodo lista=arregloDinamico(5);
 	for(int i=0;i<lista.tamanio;++i)
		set(lista,i, (i+1)%2==0 ? i+1 : (3+i)/2);
	for(int i=0;i<lista.tamanio;++i)
		printf("%d ",lista.arreglo[i]);
	return 0;
}


