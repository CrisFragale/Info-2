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