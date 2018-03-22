#include "cristian.h" 

void llenovector (coordenada* coord, int tamano) 
{
	int i=0;
	printf("llene su vector \n");
	for (i=0;i<tamano;i++)
	{
		printf("\nX:");
		scanf("%d",&coord[i].x); // (ocoord +i)-> x
		printf("\nY:");
		scanf("%d",&coord[i].y); // (ocoord +i)-> y

	}
	return ;
}
