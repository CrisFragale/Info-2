#include "cristian.h"

int main (void)
{
		nodo_t* h=NULL;
		nodo_t* aux;
	
		int dato;

		scanf("%d",&dato);
		while (dato!=-1)
		{
			insertarini(&h,dato);
			scanf("%d",&dato);
		}
		printf("ingrese el dato a buscar \n");
		scanf("%d",&dato);
		aux= busqueda (h,dato);
		if(aux==NULL)return 0;
		printf("dato buscado %d",aux->a);
		return 0;
} 
