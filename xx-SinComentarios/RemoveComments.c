#include<stdio.h>

int main(){

	typedef enum STATE {INICIO,PC,INS,FCS,INM,PFM,FCM} state;
	typedef	enum TRANSITIONS {BARRA,ASTERISCO,EOC,NUEVALINEA} trans;
	//typedef enum STATE state;
	//typedef enum TRANSITIONS trans;
	state estado=INICIO;
	//FILE* archivo=fopen("prueba.txt","r");

	const int CANTIDAD_ESTADOS = 7;
	const int CANTIDAD_TRANSICIONES = 4;
	state TT[CANTIDAD_ESTADOS][CANTIDAD_TRANSICIONES]; 
	
	TT[INICIO][BARRA] = PC;
	TT[INICIO][ASTERISCO] = INICIO;
	TT[INICIO][EOC] = INICIO;
	TT[INICIO][NUEVALINEA] = INICIO;
	TT[PC][BARRA] = INS;
	TT[PC][ASTERISCO] = INM;
	TT[PC][EOC] = INICIO;
	TT[PC][NUEVALINEA] = INICIO;
	TT[INS][BARRA] = INS;
	TT[INS][ASTERISCO] = INS;
	TT[INS][EOC] = INS;
	TT[INS][NUEVALINEA] = FCS;
	TT[FCS][BARRA] = PC; 
	TT[FCS][ASTERISCO] = INICIO;
	TT[FCS][EOC] = INICIO;
	TT[FCS][NUEVALINEA] = 
	TT[INM][BARRA] = INM;
	TT[INM][ASTERISCO] = PFM;
	TT[INM][EOC] = INM;
	TT[INM][NUEVALINEA] = INM;
	TT[PFM][BARRA] = FCM;
	TT[PFM][ASTERISCO] = INM;
	TT[PFM][EOC] = INM;
	TT[PFM][NUEVALINEA] = INM;
	TT[FCM][BARRA] = PC; 
	TT[FCM][ASTERISCO] = INICIO;
	TT[FCM][EOC] = INICIO;
	TT[FCM][NUEVALINEA] = INICIO;
	
	for(int i=0;i<=CANTIDAD_ESTADOS;i++)
		for(int j=0;j<=CANTIDAD_TRANSICIONES;j++)
			printf("%d\n",TT[i][j]);
	
	/*
	int c;
	while((c=getchar())!=EOF){
		if(estado==FCM||estado==FCS)estado=INICIO;		
		switch(c){
			case '/':
				if (estado==INICIO)
					estado=PC;
				else if(estado==PC){
					estado=INS;
					while((c=getchar())!=EOF && c!='\n')
						;
					estado=FCS;
					printf("\n");
				}
				break;
			case '*':
				if(estado==PC){
					estado=INM;
					while(estado==INM){
						while((c=getchar())!='*')
							;
						estado=PFM;
						if((c=getchar())=='/')
							estado=FCM;
					}
				}
				break;
			default:
				if(estado==PC){
					estado=INICIO;
					printf("/");
				}
				printf("%c",c);
		}
	}*/
	return 0;
	
}
