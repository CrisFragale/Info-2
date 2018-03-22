#include "cristian.h"

int extraerNumero( char * str )
{
	char *aux;
	char V[100];
	int suma,i;
	aux=strstr(str,"suma:");
	if((aux)==NULL)return (-1);

	aux=(aux + 5);
    for(i=0;*(aux+i)!='\0';i++)
    {
    	V[i] = *(aux + i);
    }
    V[i]='\0';
    suma=atoi(V);
    return suma;
}

