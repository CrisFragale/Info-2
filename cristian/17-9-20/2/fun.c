#include "cristian.h"


void cuentapalabras(FILE* fpp, int* palabras)
{
	char buff[40];
	palabras[0]=0;
	palabras[1]=0;
	fscanf(fpp,"%s",buff);
	while(feof(fpp)==0)
	{
		palabras[0]=palabras[0]+1;
		if(strcmp("diodo",buff)==0)
		{
			palabras[1]=palabras[1]+1;
		}
		fscanf(fpp,"%s",buff);
	}
	fclose(fpp);

	return ;
}