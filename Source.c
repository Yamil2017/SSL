#include<stdio.h>

int main() {

	typedef enum {OUT,IN} State;
	State estado = OUT;
	int caracter,n=0;
	char palabra[40];
	comienzo:
	while((caracter=getchar())!=EOF)
		switch (caracter) {
		case '\n':
			if (estado == IN) {
				palabra[n] = '\0';
				n = 0;
				estado = OUT;
				printf("%s\n", palabra);
			}
			break;
		case ' ':
			if (estado == IN) {
				palabra[n] = '\0';
				n = 0;
				estado = OUT;
				printf("%s\n", palabra);
			}
			break;
		case '\t':
			if (estado == IN) {
				palabra[n] = '\0';
				n = 0;
				printf("%s\n", palabra);
				estado = OUT;
			}
			break;
		default:
			if (caracter <= 'z' && caracter >= 'a' || caracter >= 'A' && caracter <= 'Z') {
				if (estado == OUT)estado = IN;
				palabra[n] = caracter;
				n++;
			}
			else {
				if (estado == IN) {
					estado = OUT;
					n = 0;
					/*while (getchar() != EOF || getchar() != ' ' || getchar() != '\n' || getchar() != '\t');*/
				}
				printf("cadena no reconocida encontrada\n");
			}
		}
	return 0;
}