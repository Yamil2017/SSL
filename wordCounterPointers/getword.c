#include<stdio.h>
#include<ctype.h>
#include"getword.h"

#define MAXBUF 100

char buf[MAXBUF];
int bp = 0;

int getch(void){
    return (bp>0)?buf[--bp]:getchar();
}

void ungetch(int letra){
    if(bp<MAXBUF)
        buf[bp++]=letra;
    else
        printf("buffer full\n");
}

int getword(char* word, int limite){
    int c;
    char*palabra = word;
    while(isspace(c=getch()));
    if(c!=EOF)
        *palabra++=c;
    if(!isalpha(c)){
        *palabra='\0';
        return c;
    }
    for(;--limite>0;palabra++)
        if(!isalnum(*palabra=getch())){
            ungetch(*palabra);
            break;
        }
    *palabra='\0';
    return palabra[0];
}