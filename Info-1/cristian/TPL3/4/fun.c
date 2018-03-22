#include "cristian.h"
 
int ocultarPalabra( char * oracion, char * palabra)
 {  
 	int encontradas=0;
 	char* aux;
 	aux=(oracion-1);
 	while(aux!=NULL)
 	{
       aux++;
       aux=my_strstr(aux,palabra);
       if(aux!=NULL)
       {
 //           printf("\"%s\"",aux);       		
       		for( ;*(aux)!=' '&&*(aux)!='\n'&&*(aux)!='\0' ;aux++)
         	       {
       			*(aux)='*';
      	   	 }
       }
       encontradas++;

//      printf("%s",oracion);
   }
 	   return(encontradas-1);
 } 

 
