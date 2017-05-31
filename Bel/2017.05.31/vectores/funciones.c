#include <stdio.h>
void cargaVector(int *v, int tam){
	int i;
	for(i=0; i<tam; i++){
		scanf("%d", &v[i]);
	}
}

void muestraDatos(int *v, int tam){
	int i;
	for (i=0; i<tam; i++){
		printf("el valor del vector en %d es: %d\n", i, v[i]);
	}
	printf("\n");
}

void promedio(int *v, int tam){
	int suma=0;
	float prom=0;
	int i;
	for (i=0; i<tam; i++){
		suma+=v[i];
	}
	prom=(float)suma/tam;
	printf("el promedio es: %.2f\n", prom);
}