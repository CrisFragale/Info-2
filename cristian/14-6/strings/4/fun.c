 #include"cristian.h"
 
 int encontrar (char* frase, char* palabra)
 {  
 	int encontradas=0;
 	char* aux;
 	aux=(frase-1);
 	while(aux!=NULL)
 	{
       aux++;
       aux=strstr(aux,palabra);
       encontradas++;

 	}
 	return(encontradas-1);
 } 
