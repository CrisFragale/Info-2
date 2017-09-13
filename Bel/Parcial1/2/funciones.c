#include "parcial.h"
int extraerNumero( char * str ){
	char* dir;
	char aux[TAM];
	int numero=0;
	int i=0;
	dir=strstr(str, "suma:");
	if (dir!=NULL){
		dir=dir+5;
		numero=atoi(dir);
		printf("ahora numero vale: %d\n", numero);
	}
	else{
		return -1;
	}
	return numero;
}