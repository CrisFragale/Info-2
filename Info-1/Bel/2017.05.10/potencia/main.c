#include "potencia.h"
int main(){
	int x, y, resultado;
	scanf ("%d,%d", &x, &y);
	resultado=potencia(x, y);
	printf("%d\n", resultado);
	return 0;
}