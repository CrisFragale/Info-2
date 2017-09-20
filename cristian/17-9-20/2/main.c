#include "cristian.h"

int main (void)
{

	FILE* fpp;
	int palabras[2];
	fpp = fopen("prueba.txt", "r+");
	if(fpp==NULL)return 0;
    cuentapalabras(fpp,palabras);
    printf("hay %d palabras y la palabra diodo aparece %d veces \n",palabras[0], palabras[1]);
	return 0;
} 
