#include <stdio.h>
int main(){
	char varChar = 67;
	short int varShort = 333;
	float varFloat = 1.27;
	double varDouble = 2.7172;
	printf("La letra de varChar es: '%c' y su valor ascii es: %hhd \nEl valor de varShort es: %hd \nEl valor de varFloat es: %.2f \nEl valor de varDouble es: %.4lf\n", varChar, varChar, varShort, varFloat, varDouble);
	return 0;
}