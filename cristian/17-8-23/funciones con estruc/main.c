#include "cristian.h"

int main (void)
{
		nodo_t* h=NULL;
		nodo_t* aux;
	
		dato_t dato;

		scanf("%d",&dato.a);
		while (dato.a!=-1)
		{
			insertarfin(&h,dato);
			scanf("%d",&dato.a);
		}
		printf("ingrese el dato a buscar \n");
		scanf("%d",&dato.a);
		aux= busqueda (h,dato);
		if(aux==NULL)return 0;
		printf("dato buscado %d \n",aux->dato.a);
		printf("ingrese el dato a ingresar en la lista \n");
		scanf("%d",&dato.a);
		insetarorden (&h,dato);
		printf("nueva lista \n");
		imprimir (h);
		scanf("%d",&dato.a);
		eliminar(&h,dato);
		imprimir (h);
		return 0;
} 
