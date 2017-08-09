#include "cristian.h" 

int main (void)
{
	int cantidad,maximo;
	scanf("%d",&cantidad);
	int * V=NULL;
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
	}
	printf("el mayor fue %d",maximo);
	free(V);
	V=NULL;
	return 0;
}