#ifndef CONVERSION_H
#define CONVERSION_H

float celsiusToFahrenheit(int celsius){
	float fahrenheit=9*celsius/5+32;
	return fahrenheit;
}

float fahrenheitToCelsius(int fahrenheit){
	float celsius=5*fahrenheit/9-32;
	return celsius;
}

#endif
