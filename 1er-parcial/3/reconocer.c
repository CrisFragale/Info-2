#include "cristian.h"

int reconocer (char * reco)
{
	int i;
	for (i=0;*(reco+i)!='\0';i++)
	{
		if(*(reco+i)<=57 && *(reco+i)>=48)
		{
		}else{
			return 1;
		}
	}
	return 0;
} 
