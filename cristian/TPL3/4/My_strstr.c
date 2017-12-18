#include "cristian.h"

char* my_strstr(char* oracion, char* palabra)
{
	int i,j,k = 0,tamano;
	char* aux2 = NULL;
	tamano=strlen(palabra);
	for(i=0;*(oracion+i)!='\0';)
	{
		j=0;
		while (j<tamano && k==0)
		{
			if(*(oracion+i+j)==*(palabra+j))
			{
				aux2=(oracion-j);
				k=0;
			}else{
				k=1;
			}
			j++;
			//printf("j: %d\n", j);
		}

		while(k==0)
		{
			printf("SALEEE \n");
			return aux2;
		}
		k=0;
		i++;
		printf("i: %d\n", i);	
	
	}
	return NULL;	
} 
