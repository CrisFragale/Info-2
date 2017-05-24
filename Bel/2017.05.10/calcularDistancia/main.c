#include "distancia.h"

int main(){
	float res;
	int a1, a2, b1, b2;
	printf("ingrese los valores de x e y de origen separados por una coma un espacio y luego los x e y finales separados por coma.\n ejemplo: 1,2 3,4\n");
	scanf("%d,%d %d,%d", &a1, &b1, &a2, &b2);
	res=distancia(a1, b1, a2, b2);
	printf("%f\n", res);
	return 0;
}
