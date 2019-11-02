#include"String.h"
#include<stdlib.h>//malloc

char* Power(char* cadena,const int rep){
	int longitud=GetLength(cadena);
	char* concatenado=malloc(longitud*rep+1);
	char* aux=concatenado;
	for(int i=0;i<rep;i++)
		for(int j=0;j<longitud;j++){
			*aux=*(cadena+j);
			aux++;
		}
	*aux='\0';
	//cadena=concatenado;
	//free(concatenado);
	return concatenado;
}

short int elementos;
short int GetLength(char* cadena){
	char*aux=cadena;
	if(*cadena=='\0'){
		short int total=elementos;
		elementos=0;
		return total;
	}
	else{
		elementos++;
		aux++;
		return GetLength(aux);
	}
/*
	short int elementos=0;
	char *token=cadena;
	while(*token!='\0'){
		elementos++;
		token++;
	}
	return elementos;*/
}


_Bool IsEmpty(char*palabra){
	return *palabra=='\0'?1:0;
	/*_Bool salida=*palabra=='\0'?1:0;
	return salida;*/
}

short int pos=0;

short int GetPos(char* cadena, char caracter){
	short int final;
	char* aux=cadena;
	if(*aux=='\0'){
		pos=0;
		return -1;
	}
	else{
		if(*(aux+pos)==caracter){
			final=pos;
			pos=0;
			return final;
		}
		else{
			pos++;
			return GetPos(cadena,caracter);
		}
	}
}
