#include "orden.h"
void myBurbujeo (int *v, int tam){
	int vueltas;
	int flag = 0;
	int aux;
	int i;
	for (vueltas = 0; vueltas < tam-1 && flag == 0; vueltas++){
		flag = 1;
		for(i=0; i<(tam-1-vueltas) ; i++){
			if (v[i] < v[i+1]){
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
				flag = 0;
			}
		}
	}
}