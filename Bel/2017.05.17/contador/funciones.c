#include <stdio.h>
void contadorDeNumeros(int *contar){
	int a;
	int count;
	printf("ingrese un numero positivo. para finalizar, presione 0.\n");
	scanf("%d", &a);
	while(a!=0){
		if(a>0){
			count++;
		}
		scanf("%d", &a);
	}
	*contar=count;
}