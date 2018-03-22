#include "cristian.h" 

int main (void)
{
	int cantidad,maximo,mas;
	scanf("%d",&cantidad);
	int * V=NULL;
	int * aux;
	V=(int*) malloc (cantidad*sizeof(int));
	if(V==NULL)exit (-1);
	scanf("%d",V);
	maximo=V[0];
	for (int i = 1; i < cantidad; i++)
	{
		scanf("%d",&V[i]);
		if(V[i]>maximo)
			{	
				maximo=V[i];
			}
		if(i==(cantidad-1))
		{
			printf("Queres ingresar mas numeros? cuantos?");
			scanf("%d",&mas);
			if(mas>0)
				{	

					cantidad+=mas;
					aux=(int*) realloc(V,cantidad*sizeof(int));
					if(aux==NULL)exit (-1);
					V=aux;
				}
		}	
	}
	printf("el mayor fue %d",maximo);
	free(V);
	V=NULL;
	return 0;
}