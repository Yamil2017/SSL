#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>//strcmp
#include"String.h"

int main(){

	char* cadenaNoVacia="Sintaxis y semántica de los lenguajes de programación";
	char* cadenaVacia="";
	assert(IsEmpty(cadenaNoVacia)==0);
	assert(IsEmpty(cadenaVacia)==1);
	assert(GetLength(cadenaVacia)==0);
	assert(GetLength(cadenaNoVacia)==53);
	assert(GetLength("Hola")==4);
	assert(GetLength(cadenaNoVacia)==53);
	assert(strcmp(Power("Hola",4),"HolaHolaHolaHola")==0);
	assert(strcmp(Power("Hola",4),"HolaHolaHola")!=0);
	assert(GetPos("flubundeferr",'r')==10);
	assert(GetPos("flubundeferr",'b')==3);
	printf("%d\n",GetPos("flubundeferr",'k'));
	printf("%d\n",GetPos("flubundeferr",'d'));
	printf("%d\n",GetPos("flubundeferr",'k'));
	//assert(GetPos("flubundeferr",'k')==-1); //No funciona



	return 0;
}
