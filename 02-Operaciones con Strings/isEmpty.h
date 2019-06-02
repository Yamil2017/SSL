#ifndef ISEMPTY_H
#define ISEMPTY_H

short int isEmpty(char*palabra){
	short int salida=*palabra=='\0'?1:0;
	return salida;
}
/*
char* isEmpty(char*palabra){
	char*salida=*palabra=='\0'?"true":"false";
	return salida;
}*/


#endif
