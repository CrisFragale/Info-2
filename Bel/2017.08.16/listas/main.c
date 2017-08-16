#include "listas.h"
int main(){
	nodo_t * h=NULL;//h vacio
	int dato;
	scanf("%d", &dato)
	while(dato!=-1){
		insertarFin(&h, dato);
		scanf("%d", &dato);
	}
	return 0;
}