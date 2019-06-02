#include<stdio.h>
#include<stdlib.h>
#include"isEmpty.h"
#include"getLength.h"
#include"concat.h"
//short int isEmpty(char* );

int main(){
	char* cadena="Yamil de Ituzaingo!!";
	if(!isEmpty(cadena))	
		printf("%s %d\n",cadena,isEmpty(cadena));
	else
		printf("Cadena vacia!!!, %d\n",isEmpty(cadena));
	//printf("%s\n",pointAux);
	printf("%d\n",getLength(cadena));
	printf("%s\n",concat(cadena,4));
	return 0;

}
/*
short int isEmpty(char* palabra){
	short int respuesta=*palabra=='\0'? 1: 0;
	return respuesta;
}*/
