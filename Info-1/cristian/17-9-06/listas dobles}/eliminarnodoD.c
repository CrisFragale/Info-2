#include "cristian.h" 

int eliminarnodoD (node_t **h, node_t *rm)
{
	node_t i=*h;
	while(i!=rm && i!=NULL){
		i=i->next;
	}
	if(i==NULL)return -1;
	if(i->prev==NULL)
	{
		
	}
	
} 
