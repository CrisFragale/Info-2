#include "cristian.h" 


int main (void)
{
	float moduloT;
	coordenada cord[TAM];
	llenovector(cord,TAM);
    moduloT=modulo(cord, TAM);
    printf("el modulo fue %.2f",moduloT);
    return 0;
}