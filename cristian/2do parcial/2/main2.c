#include "cristian2.h"

int main (int argc, char * argv[])
{
	nodo_t *ptr_h=NULL;
	int error,temasEscritos=0;
	error= lecturaTemas (&ptr_h, argv[1]);
	imprimir(ptr_h);
	printf("error: %d \n",error);
	temasEscritos=almacenar(ptr_h, argv[2]);
	printf("temas: %d \n",temasEscritos);
	return 0;

}


