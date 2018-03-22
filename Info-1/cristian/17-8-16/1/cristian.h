#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 10

typedef struct corde {
	int x;
	int y;
}coordenada;

void llenovector (coordenada* coord, int tamano);
float modulo (coordenada* coord, int tamano);