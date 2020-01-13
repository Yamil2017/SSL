#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"keywordStruct.h"
#include"iofunc.h"

#define MAXWORD 100

int binsearch(char*,struct key[],int);

int main(){

    char palabra[MAXWORD];
    int n;
    while(getword(palabra,MAXWORD)!=EOF)
        if(isalpha(palabra[0]))
            if((n=binsearch(palabra,keytab,NKEYS))>=0)
                keytab[n].count++;

    for(n=0;n<NKEYS;n++)
        if(keytab[n].count>0)
            printf("keyword: %8s counted: %4d\n",keytab[n].word,keytab[n].count);

    printf("End of program, autodestruction rutine activated, god save you all\n");

    return 0;

}

int binsearch(char *word,struct key tab[],int limit){
    int low,high,med,cond;
    low=0;
    high=limit-1;
    while (low<=high){
        med=(low+high)/2;
        if((cond=strcmp(word,tab[med].word))<0)
            high=med-1;
        else if(cond>0)
            low=med+1;
        else
            return med;
    }
    return -1;
}