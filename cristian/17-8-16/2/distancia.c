#include "cristian.h" 

// no calcula distancias solo modulos.
float modulo (coordenada* coord, int tamano)
{
	int i=0;
	float modulos=0;
	for (i=0;i<tamano;i++)
	{
		modulos+=sqrt(((coord[i].x)*(coord[i].x))+((coord[i].y)*(coord[i].y)));
	}
	return (modulos);
} 
