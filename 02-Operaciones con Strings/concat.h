#ifndef CONCAT_H
#define CONCAT_H

char* concat(char* cadena,int rep){
	int longitud=getLength(cadena);
	char* concatenado=malloc(longitud*rep+1);
	char* aux=concatenado; 
	for(int i=0;i<rep;i++)
		for(int j=0;j<longitud;j++){
			*aux=*(cadena+j);
			aux++;
		}
	*(aux+longitud)='\0';
	return concatenado;
}

#endif
