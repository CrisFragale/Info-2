#include "leerArch.h"
void lee(FILE *fp){
	char palabra[40];
	int countP = 0;
	int countDiodo = 0;
	fscanf(fp, "%s", palabra);
	while(feof(fp)==0){
		countP++;
		if(strcmp(palabra, "diodo")==0){
			countDiodo++;
		}
		fscanf(fp, "%s", palabra);
	}
	printf("la cant de palabras es: %d\n la cant de veces que aparece diodo es: %d \n", countP, countDiodo);
}