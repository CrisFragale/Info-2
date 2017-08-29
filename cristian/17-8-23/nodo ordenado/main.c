#include "cristian.h"

int main (void)
{
		nodo_t* h=NULL;
		nodo_t* aux;
	
		int dato;

		scanf("%d",&dato);
		while (dato!=-1)
		{
			insertarfin(&h,dato);
			scanf("%d",&dato);
		}
		printf("ingrese el dato a buscar \n");
		scanf("%d",&dato);
		aux= busqueda (h,dato);
		if(aux==NULL)return 0;
		printf("dato buscado %d \n",aux->a);
		printf("ingrese el dato a ingresar en la lista \n");
		scanf("%d",&dato);
		insetarorden (&h,dato);
		printf("nueva lista \n");
		imprimir (h);
		scanf("%d",&dato);
		eliminar(&h,dato);
		imprimir (h);
		return 0;
} 
