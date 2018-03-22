#include "str.h"
int my_strcmp (char *sOrigen, char *sDest){
	int i;
	int j;
	int aux=0;
	for (i = 0; i < strlen(sOrigen); i++)
	{
		for(j=0; j< strlen(sDest); j++){
			if(sOrigen[i+j]==sDest[j]){
				aux++;
			}
		}
	}
	if (aux>=strlen(sDest)){
		return 1;
	}
	else{
		return 0;
	}
}