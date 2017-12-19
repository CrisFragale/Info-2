#include "cristian2.h"

int almacenar(nodo_t *ptr_h, char *archivoSalida)
{
	FILE* fd2;
	int temas=0;
	fd2=fopen(archivoSalida,"w+");
	if(fd2==NULL)return -1;
	while(ptr_h!=NULL)
	{
		fprintf(fd2,"NombreTema: %s \n Autor: %s \n CantidadReproducciones %d \n",ptr_h->datos.infoTema.Nombre,ptr_h->datos.infoTema.Autor,ptr_h->datos.cantidad);
		ptr_h=ptr_h->next;
		temas++;
	}
	return temas;

} 
