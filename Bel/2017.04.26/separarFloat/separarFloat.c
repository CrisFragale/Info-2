#include <stdio.h>
int main(){
	float nume;
	int entero;
	printf("ingrese un numero decimal\n");
	scanf("%f", &nume);
	entero = (int) nume;
	nume = nume-entero;
	printf("la parte entera es %d y la parte decimal es %f \n", entero, nume);
	return 0;
}