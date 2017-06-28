#include "cristian.h"

char* my_strstr(char* oracion, char* palabra)
{
	int i,j,k = 0,tamano;
	char* aux2 = NULL;
	tamano=strlen(palabra);
	for(i=0;*(oracion+i)!='\0';)
	{
	    for( j=0 ;j < tamano && k==0 && *(oracion+i+j)!='\0';)
	    {    
	    	if(*(oracion+i+j)==*(palabra+j))
	    	{
                aux2=(oracion-j);
                k=0;
	    	}else{
	    		k=1;
	    	}
	    	j++;
	    	printf("j: %d\n", j);
	    }
	    
	    if(k==0)
	    {
	    	return(aux2);
	    }
	    else
	   	{
	   		k = 0;
	   	}

	    i++;
	    printf("%d\n", i);	
	
	}
	return NULL;	
}