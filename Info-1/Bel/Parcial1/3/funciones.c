#include "parcial.h"
int sumador(char **vector, int tam){
	int num=0;
	int i, j;
	for (i = 1; i < tam; i++){
		for ( j= 0; vector[i][j]!='\0'; j++){
			num+=atoi(vector[i]);
		}
	}
	return num;
}
