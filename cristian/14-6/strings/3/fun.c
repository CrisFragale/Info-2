#include"cristian.h"

int verificacion2 (char* frase, char* palabra)
{  
	char * ver;
	ver=strstr(frase,palabra);
	if(ver==NULL)return(0);
	return(1);
}