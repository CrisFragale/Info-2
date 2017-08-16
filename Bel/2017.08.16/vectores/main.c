#include "vectores.h"
int main(void){
	int n=0;
	float total;
	coord_t* cord = NULL;

	printf("ingrese el largo del vector\n");
	scanf("%d", &n);
	cord = (coord_t*)malloc(n*sizeof(coord_t));
	
	llenoVector(cord, n);
	total=sumatoria(cord,n);
	printf("%f\n", total);

	free(cord);
	return 0;
}