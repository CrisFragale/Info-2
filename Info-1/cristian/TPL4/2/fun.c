#include "cristian.h" 

int insertarfin (nodo_t ** inicio, dato_t dt)
{
		nodo_t* aux, *aux2;
		aux=(nodo_t*)malloc (sizeof(nodo_t));
		if(aux==NULL)return -1;
		aux->next=NULL;
		aux->dato.codigo=dt.codigo;
		aux->dato.cantidad=dt.cantidad;
		if(*inicio==NULL)
		{
			*inicio=aux;
			return 1;
		}
		for(aux2=*inicio;aux2->next!=NULL;aux2=aux2->next);
		aux2->next=aux;
	    return 0;

} 

int insert (nodo_t ** ptrH, dato_t dt)
{
	nodo_t* aux, *aux2, *buscado=NULL;
	if(*ptrH== NULL)
	{
		aux=(nodo_t*)malloc (sizeof(nodo_t));
		if(aux==NULL)return -1;
		aux->next=NULL;
		aux->dato.codigo=dt.codigo;
		aux->dato.cantidad=dt.cantidad;
		*ptrH=aux;
	}
	else
	{
	    aux2 = *ptrH;
	    while (aux2!=NULL)
			{
			if(aux2->dato.codigo==dt.codigo)
				{			
					buscado=aux2;
				}
			aux2=aux2->next;
			}
		if(buscado!=NULL)
			{
				buscado->dato.cantidad=buscado->dato.cantidad + dt.cantidad;
			}else {
				insertarfin(ptrH,dt);
			}return 0;	

	}	
	return 0;	

}

 
