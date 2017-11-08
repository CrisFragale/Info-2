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


nodo_t* busqueda (nodo_t *i, int d)
{
	nodo_t* buscado;
	while (i!=NULL)
		{
		if(i->D.minutos==d)
			{			
				buscado=i;
				return buscado;
			}
		i=i->next;
		}
	return i;
}



int velocidadMedia(nodo_t *ptr_h, int minin, int minfin )
{
	int velocidad;
	nodo_t *aux;
	nodo_t *aux2;
	aux=busqueda(ptr_h,minin);
	if(aux==NULL)return -1;
	aux2=busqueda(ptr_h,minfin);
	if(aux==NULL)return -1;
	velocidad=(float)(((aux2->D.kilometro)-(aux->D.kilometro))/((aux2->D.minutos)-(aux->D.minutos))*60);
	return (velocidad);
}