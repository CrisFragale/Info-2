#include "cristian.h"

int sumador( char ** vector, int tam ) 
{  
	int i,reco,aux,suma=0;
	for(i=1;i<=tam;i++)
	{
		reco=reconocer(vector[i]);
		if(reco==0)
		{    
  			aux=atoi(vector[i]);
         	suma=suma+ aux;
		}
	}
	return (suma);
}