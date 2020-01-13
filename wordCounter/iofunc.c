#include"iofunc.h"
#include<stdio.h>
#include<ctype.h>

#define MAXBUF 100
char buf[MAXBUF];
int bp = 0;

int getch(void){
    return (bp>0)?buf[--bp]:getchar();
}

void ungetch(int c){
    if(bp>=MAXBUF)
        printf("buffer completo!!!\n");
    else
        buf[bp++]=c;
}

int getword(char* word,int limit){
    
    int c;
    char* w =word;

    while(isspace(c=getch()));

    if(c!=EOF)
        *w++ = c;

    if(!isalpha(c)){
        *w='\0';
        return c;
    }
    for(;--limit>0;w++)
        if(!isalnum(*w=getch())){
            ungetch(*w);
            break;
        }
    
    *w='\0';
    return word[0];
}