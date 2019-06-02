#ifndef GETLENGTH_H
#define GETLENGTH_H

short int getLength(char* cadena){
	short int elementos=0;
	char *token=cadena;
	while(*token!='\0'){
		elementos++;
		token++;
	}
	return elementos;
}

#endif

