#include "cristian.h"

int main (void)
{
		nodo_t* h=NULL;
		int dato;

		scanf("%d",&dato);
		while (dato!=-1)
		{
			insertarfin(&h,dato);
			scanf("%d",&dato);
		}
		return 0;
} 
