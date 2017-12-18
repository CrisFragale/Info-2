/*  Realice una función para imprimir la lista generada en el punto 1. Indique cual será su
prototipo.


alumno: cristian fragale
 */

#include "cristian.h"

int main (void)
{
		nodo_t* ptrH=NULL;
		dato_t dt;
		int a=0;
        while(a!=4)
        {
			printf("ingrese el codigo \n");
			scanf("%d",&dt.codigo);
			printf("ingrese la cantidad \n");
			scanf("%d",&dt.cantidad);
			insert(&ptrH,dt);
			a++;
		}
		imprimir(ptrH);
		return 0;
} 


 
