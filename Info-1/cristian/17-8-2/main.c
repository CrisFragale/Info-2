#include "cristian.h"

int main (void)
{
	char *palabras[TAM];
	char buff[250];
	int tam,i;
	for (i=0;i<TAM;i++)
	{
		scanf("%s",buff);
	    tam=strlen(buff+1);
	    palabras[i]=(char*)malloc(tam);
	    strcpy(palabras[i],buff);
	}
	i=mostrar_palabras(palabras);
    for (i=0;i<TAM;i++)
    {
    	free(palabras[i]);
    }
    return(0);
} 
