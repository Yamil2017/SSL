#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "Conversion.h"
//float fahrenheitToCelsius(int);
//float celsiusToFahrenheit(int);

int main(){
	const int T_MINIMA=0,T_MAXIMA=200;
	//srand(time(0));
	printf("CELSIUS\t\tFAHRENHEIT\n\n");
	for(int i=T_MINIMA;i<T_MAXIMA;i++){
		//int temperatura=rand()%T_MAXIMA+T_MINIMA;
		printf("%d\t\t%.2f\n",i,celsiusToFahrenheit(i));
	}
	printf("FAHRENHEIT\tCELSIUS\n\n");
	for(int i=T_MINIMA;i<T_MAXIMA;i++)
		printf("%d\t\t%.2f\n",i,fahrenheitToCelsius(i));
	return 0;
}

/*
float fahrenheitToCelsius(int fahrenheit){
	float celsius=5*(float)fahrenheit/9-32;
	return celsius;
}

float celsiusToFahrenheit(int celsius){
	float fahrenheit=9*(float)celsius/5+32;
	return fahrenheit;
}*/
