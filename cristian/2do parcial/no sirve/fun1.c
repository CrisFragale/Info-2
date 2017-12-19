#include "cristian.h"

int lecturaTemas (nodo_t **ptr_h, char *archivo)
{	
	int fd, deam, error=2;
	dato_t aux;

	fd=open (archivo, O_RDONLY);
	deam = read(fd,&aux,sizeof(aux));
	while (deam!=0)
	{
		if(error==2)
			{
				error=insertarini(ptr_h,aux);
				(*ptr_h)->datos.cantidad--;
			}
		if(corroborar(ptr_h,aux)==0)
		{
			error=insertarini(ptr_h,aux);
			if(error!=0)return -1;
		}
		deam = read(fd,&aux,sizeof(aux));
	}
	close(fd);
	return 0;
}




int insertarini (nodo_t ** inicio, dato_t d )
{
		nodo_t* aux;
		aux=(nodo_t*)malloc (sizeof(nodo_t));
		if(aux==NULL)return -1;
		aux->next=NULL;
		aux->datos.infoTema=d.infoTema;
		aux->next= *inicio;
		*inicio=aux;
		return 0;
} 

int corroborar(nodo_t ** inicio, dato_t d )
{
	nodo_t *nada;
	nada= busqueda((*inicio),d);
	

	if(nada==NULL)
    {
    	return 0;
    }else{
    	nada->datos.cantidad++;
    	return 1;
    }
}



nodo_t* busqueda (nodo_t *i, dato_t d)
{
	nodo_t* buscado;
	while (i!=NULL)
		{
		if(i->datos.infoTema.codigo==d.infoTema.codigo)
			{			
				buscado=i;
				return buscado;
			}
		i=i->next;
		}
	return NULL;
}


void imprimir (nodo_t *i)
{
	while (i!=NULL)
	{
		printf("dato:\n codigo: %d \n nombre: %s \n autor: %s \n cantidad: %d \n",i->datos.infoTema.codigo,i->datos.infoTema.Nombre,i->datos.infoTema.Autor,i->datos.cantidad);
		i=i->next;
	}
	return;
} 