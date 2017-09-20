#include "leerArch.h"
int main(){
	FILE *fp;
	fp = fopen("/home/ash/Documents/INFO/2017.09.20/leerArchivo/palabra.txt", "r+");
	lee(fp);
	return 0;
}