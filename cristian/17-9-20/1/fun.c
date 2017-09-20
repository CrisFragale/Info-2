#include "cristian.h"


int escrivoarchivo (char* buff, FILE* fpp)
{
	if(strcmp("fin",(char*)buff)==0)
	{
		return -1;
	}
	fprintf (fpp, "%s ;" ,buff);
	return 0;
}
