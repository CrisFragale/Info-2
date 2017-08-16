#include "cristian.h" 


int main (void)
{   
	int tamano;
	float moduloT;
	coordenada* cord;
	printf("Cuantos puntos va a ingresar?\n");
	scanf("%d",&tamano);
	cord=(coordenada*) malloc(tamano*sizeof(coordenada));
	llenovector(cord,tamano);
    moduloT=modulo(cord, tamano);
    printf("el modulo fue %.2f",moduloT);
    free(cord);
    return 0;
}