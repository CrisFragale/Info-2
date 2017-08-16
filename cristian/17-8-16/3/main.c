#include "cristian.h"

int main (void)
{
		nodo_t* h=NULL;
		nodo_t* aux;
		nodo_t* i;

		scanf("%d",&dato);
		while (dato!=-1)
		{
			aux=(nodo_t*)malloc (sizeof(nodo_t));
			aux->a=dato;
			if(h==NULL)h=aux;
			aux->next=NULL;
			i=h;
			while(i->next!=NULL)
			{
				i=i->next;
			}
			i->next=aux;
		}
		return 0;
} 
