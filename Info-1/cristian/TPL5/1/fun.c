 #include "cristian.h"

int lecturaPacientes (nodo_t **dir_h , char *archivo )
{
   int fd,deam,error;
   paciente_t paciente;

   fd=open(archivo,O_RDONLY);
   if(fd==-1)return -3;
   deam=read(fd,&paciente, sizeof(paciente_t));
   if(deam==-1)return(deam);
   while (deam!=0)
   {
   	error= insetarorden (dir_h,paciente);
   	if(error==-1)return(-2);
   	deam=read(fd,&paciente, sizeof(paciente_t));
   	if(deam==-1)return(deam);
   }
   close(fd);
   return 0;
}



int insetarorden (nodo_t **h, paciente_t dato)
{
		nodo_t* aux, *j,*i;
		aux=(nodo_t*)malloc (sizeof(nodo_t));
		if(aux==NULL)return -1;
		aux->paciente=dato;
		if(*h==NULL)
		{
			*h=aux;
			aux->next=NULL;
			return (0);
		}
		if((*h)->paciente.horaTurno >= aux->paciente.horaTurno)
		{
			aux->next=*h;
			*h=aux;
			return (0);
		}
		j=*h;
		i=(*h)->next;
		while (i!=NULL && i->paciente.horaTurno <= aux->paciente.horaTurno)
		{	
			j=i;
			i=i->next;
		}
		if(i==NULL)
		{
			j->next=aux;
			aux->next=NULL;
		}else
		{	
			j->next=aux;
			aux->next=i;
		}
		return 0;

}

void imprimir (nodo_t *i)
{
	while (i!=NULL)
	{
		printf("turno %f \n",i->paciente.horaTurno);
		i=i->next;
	}
	return;
} 