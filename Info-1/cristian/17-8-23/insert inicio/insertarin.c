#include "cristian.h"

int insertarini (nodo_t inicio, int d )
{
		nodo_t* aux;
		aux=(nodo_t*)malloc (sizeof(nodo_t));
		if(aux==NULL)return -1;
		aux->next=NULL;
		aux->a=d;
		aux->next= *(inicio);
		*(inicio)=aux;

} 
