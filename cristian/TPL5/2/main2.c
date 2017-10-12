#include "cristian2.h"

int main (void) 
{
	FILE *fd1, *fd2;
	fd1=fopen("paton.txt","r+");
	fd2=fopen("prosesado.txt","r+");
	promediar(fd1,fd2);
	return 0;

}