#include"StackOfCharsModule.h"
#include<stdlib.h>
#include<stdio.h>

enum State{
	INIT='$',
	INPARENS='(',
	INBRACES='{',
	INBRACKETS='[',
	INSTRING='"'};
 
typedef enum State State;

int main(){
	State state=INIT;
	push(INIT);
	char c;
	while((c=getchar())!=EOF){
		while(c!='(' && c!='[' && c!='{' && c!='"' && c!='}' && c!=']' && c!=')' && c!=EOF)
			c=getchar();
		switch(c){
		case '(':
			state = INPARENS;
			push(INPARENS);
			break;
		case '[':
			state = INBRACKETS;
			push(INBRACKETS);
			break;
		case '{':
			state = INBRACES;
			push(INBRACES);
			break;
		case ')':
			if(state==INPARENS){
				pop();
				state=pop();
				push(state);
			}
			else {
				printf("error: parentesis desbalanceados\n");
				exit(0);
			}
			break;
		case '"':
			while((c=getchar())!='"');
			break;
		case '}':
			if(state==INBRACES){
				pop();
				state=pop();
				push(state);
			}
			else{
				printf("error: llaves desbalanceadas\n");
				exit(0);
			}
			break;	
		case ']':
			if(state==INBRACKETS){
				pop();
				state = pop();
				push(state);
			}
			else{
				printf("error: corchetes desbalanceados\n");
				exit(0);
			}
			break;
		}
	}

	if(state==INIT)
		printf("las llaves, parentesis y corchetes estan balanceados\n");
	else
		printf("hubo inconvenientes en el analisis del texto\n");

	return 0;
}
