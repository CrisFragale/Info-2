#include "cristian.h" 

int lecturaArchivo (nodo_t **prt_h, char *archivos)
{
	FILE* fd;
	fd= fopen(archivos, "r+");
	distancia_t dist;
	fscanf(fd,"%d,%d",&dist.minutos,&dist.kilometro); // leo primero para usar el FEOF
	while (feof(fd)==0)
	{	
		insertarfin(prt_h,dist);
		fscanf(fd,"%d,%d",&dist.minutos,&dist.kilometro);
	
	}
	fclose(fd);
	return 0;

}

 
int insertarfin (nodo_t ** inicio, distancia_t d)
{
		nodo_t* aux, *aux2;
		aux=(nodo_t*)malloc (sizeof(nodo_t));
		if(aux==NULL)return -1;
		aux->next=NULL;
		aux->D=d;
		if(*inicio==NULL)
		{
			*inicio=aux;
			return 1;
		}
		for(aux2=*inicio;aux2->next!=NULL;aux2=aux2->next);
		aux2->next=aux;
	    return 0;

} 


void imprimir (nodo_t *i)
{
	while (i!=NULL)
	{
		printf("min %d \n",i->D.minutos);
		printf("km %d \n",i->D.kilometro);
		i=i->next;
	}
	return;
} 