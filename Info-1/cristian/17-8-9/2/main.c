#include "cristian.h" 

int main (void)
{
	int * V=NULL;
	int cantidad;
	scanf("%d",&cantidad);
	V=generavector(cantidad);
	V=NULL;
	free (V);
	return 0;
}
