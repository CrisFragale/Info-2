#include "vectores.h"
void llenoVector(coord_t* coord, int tam){
	int i;
	for(i=0; i<tam; i++){
		printf("llene su vector con formato x,y \n");
		scanf("%d,%d", &coord[i].x, &coord[i].y);//ó (c+i)->x ó (*(c+i)).x
	}
}


float sumatoria (coord_t* coord, int tam){
	float modulo = 0;
	int i;
	float pot;
	for (i = 0; i < tam; i++){
		pot = pow(coord[i].x, 2) + pow(coord[i].y, 2);
		modulo+=(float)sqrt(pot);
	}
	return modulo;
}