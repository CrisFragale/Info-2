#include "cristian.h"

int insertarfin (nodo_t ** inicio, int d)
{
		nodo_t* aux;
		nodo_t* i;
		aux=(nodo_t*)malloc (sizeof(nodo_t));
		if(aux==NULL)return -1;
		aux->a=d;
		if(*(inicio)==NULL)*(inicio)=aux;
		aux->next=NULL;
		i=*(inicio);
		while(i->next!=NULL)
		{
			i=i->next;
		}
		i->next=aux;
		return 0;
} 
