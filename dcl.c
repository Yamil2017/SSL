#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXBUF 100
#define MAXTOKEN 100

enum {NAME,PARENS,BRACKETS};

void dcl();
void dirdcl();

int getch(void);
void ungetch(int);
int gettoken(void);
int tokentype;			//type of last token	
char token[MAXTOKEN];		//type of last string
char name[MAXTOKEN];		//identifier name
char datatype[MAXTOKEN];	//data type = int, char, etc
char out[1000];		

int main(){

	while(gettoken()!=EOF){
		strcpy(datatype,token);
		out[0]='\0';
		dcl();
		if(tokentype!='\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name,out,datatype);
	}
	return 0;
}

//dcl: parse a declarator
void dcl(){
	int ns;
	for(ns=0;gettoken()=='*';)	//count *'s
		ns++;
	dirdcl();
	while(ns-- > 0)
		strcat(out," pointer to");
}

//dirdcl: parse a direct declarator
void dirdcl(void){
	int type;
	if(tokentype=='('){
		dcl();
		if(tokentype!=')')
			printf("error: missing )\n");
	}else if(tokentype==NAME) //variable name
		strcpy(name,token);
	else
		printf("error: expected name or (dcl)\n");
	while((type=gettoken())==PARENS||type==BRACKETS)
		if(type==PARENS)
			strcat(out," function returning");
		else{
			strcat(out," array");
			strcat(out,token);
			strcat(out," of");
		}
}

int gettoken(void){
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while((c=getch())==' '||c=='\t');
	
	if(c=='('){
		if((c=getch())==')'){	 	
			strcpy(token,"()");
			return tokentype = PARENS;
		}else {
			ungetch(c);
			return tokentype='(';
		}
	}else if(c=='['){
		for(*p++=c;(*p++=getch())!=']';);	
		*p='\0';
		return tokentype = BRACKETS;
	}else if (isalpha(c)){
		for(*p++=c;isalnum(c=getch());)
			*p++=c;
		*p='\0';
		ungetch(c);
		return tokentype=NAME;
	}else
		return tokentype=c;
}

char buf[MAXBUF];
int bp=0;

int getch(void){
	return (bp>0)?buf[--bp]:getchar();
}

void ungetch(int c){
	if(bp>=MAXBUF)
		 printf("the buffer is full\n");
	else
		buf[bp++]=c;
}
			
