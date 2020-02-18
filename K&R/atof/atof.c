#include<stdio.h>
#include<ctype.h>

double stringToDouble(char*);

int main(void){
	

	char* numeroString="-3.1415";

	printf("El numero del string es: %f\n",stringToDouble(numeroString));		

	numeroString="124403.1415";

	printf("El numero del string es: %f\n",stringToDouble(numeroString));		
	return 0;
}

double stringToDouble(char* s){
	int i,sign;
	double val,power;
	for(i=0;isspace(s[i]);i++);
	sign=(s[i]=='-')?-1:1;
	if(s[i]=='+'||s[i]=='-')
		i++;
	for(val=0.0;isdigit(s[i]);i++)
		val=10*val+(s[i]-'0');
	if(s[i]=='.')
		i++;
	for(power=1.0;s[i]!='\0';i++,power*=10)
		val=10*val+(s[i]-'0');
	return sign*val/power;
}
