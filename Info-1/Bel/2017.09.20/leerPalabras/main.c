#include "palabras.h"
int main(void){
	FILE *fp;
	char pal[30];
	scanf("%s", pal);
	fp = fopen("/home/ash/Documents/INFO/2017.09.20/leerPalabras/palabras.csv", "w+");
	leepalabra(fp, pal);
	return 0;
}