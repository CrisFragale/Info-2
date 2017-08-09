 #include "cristian.h" 

int* generavector (int cantidad)
{
	int maximo;
	int * V=NULL;
	V=(int*) malloc (cantidad*sizeof(int));
	if(V==NULL)return NULL;
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
	V=NULL;
	return V;
}

