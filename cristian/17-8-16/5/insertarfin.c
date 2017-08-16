#include "cristian.h"

int insertarfin (nodo_t ** inicio, int d)
{
		nodo_t* aux, aux2;
		aux=(nodo_t*)malloc (sizeof(nodo_t));
		if(aux==NULL)return -1;
		aux->next=NULL;
		aux->a=d;
		for(aux2=*(inicio);aux2->next!=NULL;aux2=aux2->next);
		aux2->next=aux;
	    return 0;

} 
 
