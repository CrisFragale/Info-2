#include "cristian.h"

int main (int argc, char * argv[])
{
	nodo_t *ptr_h=NULL;
	int error;
	error= lecturaTemas (&ptr_h, argv[1]);
	imprimir(ptr_h);
	printf("error: %d \n",error);
	return 0;

}


