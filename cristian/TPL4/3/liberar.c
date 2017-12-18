#include "cristian.h"

void liberartoda (nodo_t ** h)
{
	nodo_t* aux;
	while (*h!=NULL)
	{
		aux=*h;
		*h=aux->next;
		free(aux);
	}
	return;
} 
