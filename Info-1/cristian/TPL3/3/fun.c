#include "cristian.h"
 
int ocultarPalabra( char * oracion, char * palabra)
 {  
 	int encontradas=0;
 	char* aux;
 	aux=(oracion-1);
 	while(aux!=NULL)
 	{
       aux++;
       aux=strstr(aux,palabra);
       if(aux!=NULL)
       {
       		for( ;*(aux)!=' ';aux++)
         	     {
					if(*(aux)!='\n')
       				{
       					*(aux)='*';
      	   	   	  }else{
      		   	 	return encontradas;
      	 	  	 }
      	   	}
       }
       encontradas++;

 	}
 	return(encontradas-1);
 } 

 
