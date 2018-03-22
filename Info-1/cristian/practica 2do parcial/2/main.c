#include "cristian.h"

int main (void)
{
	int i;
	char archivos[40];
	nodo_t *prt_h=NULL;
	printf("ingrese el nombre del archivo \n");
	scanf("%s",archivos);
	i = lecturaArchivo (&prt_h,archivos);
	imprimir(prt_h);
	i=velocidadMedia(prt_h,106,110);
	printf("%d",i);
	return 0;
}
