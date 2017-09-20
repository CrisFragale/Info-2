#include "cristian.h"

int main (void)
{

	FILE* fpp;
	int flag=0;
	char buff[40];
	fpp = fopen("palabras.csv", "w+");
    while (flag==0)
    {
		scanf("%s",buff);
		flag = escrivoarchivo(buff,fpp);
	}

	return 0;
} 
