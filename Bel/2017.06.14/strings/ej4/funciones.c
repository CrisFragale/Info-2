#include "str.h"
int encuentro (char *frase, char *palabra){
	char *aux;
	int encuentro;
	aux=frase-1;
	while(aux!=NULL){
		aux++;
		aux = strstr(aux, palabra);
		encuentro++;
	}
	return encuentro-1;
}