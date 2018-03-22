/*  Haciendo uso de la ​función del punto 1 y punto 2 realice el programa principal que lea de
teclado datos de código y cantidad para insertar en la lista hasta que el código sea -1. En ese
momento imprimir la lista resultante. Hacer uso de las funciones desarrolladas en clase y
eliminar​ ​la​ ​memoria​ ​antes​ ​de​ ​cerrar​ ​el​ ​programa.


alumno: cristian fragale
 */

#include "cristian.h"

int main (void)
{
		nodo_t* ptrH=NULL;
		dato_t dt;
		    printf("ingrese el codigo \n");
			scanf("%d",&dt.codigo);
			printf("ingrese la cantidad \n");
			scanf("%d",&dt.cantidad);
        while(dt.codigo!=-1)
        {
			insert(&ptrH,dt);
			printf("ingrese el codigo \n");
			scanf("%d",&dt.codigo);
			printf("ingrese la cantidad \n");
			scanf("%d",&dt.cantidad);
		}
		imprimir(ptrH);
		liberartoda (&ptrH);
		return 0;
} 


 
