#include "cristian.h" 

void insertfinD(node_t **h, int dt)
{
	node_t *aux=(node_t*)malloc (sizeof(node_t));
	aux->dt=dt;
	aux->next=NULL;
	aux->prev=NULL;

	node_t* i=*h;
	if(i==NULL)
	{
		*h=aux;
		return;
	}
	while (i->next!=NULL){
		i=i->next;
	}
	i->next=aux;
	aux->prev=i;
	return;
}


int eliminarnodoD (node_t **h, node_t *rm)
{
	node_t i=*h;
	while(i!=rm && i!=NULL){
		i=i->next;
	}
	if(i==NULL)return -1;
	if(i->prev==NULL)
	{
		*h->prev=NULL; // contemplo asi si es el primer nodo por eso los cambie de lugar.
		*h=i->next;
	}else{
		i->prev->next=i->next;
		if(i->next!=NULL)
		{
			i->next->prev=i->prev;
		}
	}	

	free(i);
	return 1;
} 

