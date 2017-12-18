 
#include "cristian.h"

void imprimir (nodo_t *i)

{
	while (i!=NULL)
	{
		printf("codigo y cantidad %d %d\n",i->dato.codigo,i->dato.cantidad);
		i=i->next;
	}
	return;
} 