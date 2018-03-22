#include <stdio.h>
#define CANT 10
void cargaVector(int *, int);
void muestraDatos(int *, int);
void promedio(int *, int);

int main(){
	int numeros[CANT];
	cargaVector(numeros, CANT);
	muestraDatos(numeros, CANT);
	promedio(numeros, CANT);
	return 0;
}