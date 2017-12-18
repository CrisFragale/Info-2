/* Realice una función que inserte en un lista simplemente enlazada un dato recibido como
parámetro. Dicho dato consta de un código (tipo entero) y la cantidad, la función deberá
verificar si el código recibido existe en la lista, en caso que el mismo exista se deberá
incrementar a la cantidad ya existente la cantidad recibida. En caso que el código no exista
en​ ​la​ ​lista​ ​se​ ​deberá​ ​insertar​ ​el​ ​dato​ ​en​ ​un​ ​nuevo​ ​nodo.
Su​ ​prototipo​ ​será:​​ ​int​ ​insert(​ ​nodo_t​ ​**​ ​ptrH,​ ​dato_t​ ​dt)
La​ ​estructura​ ​del​ ​dato​ ​será:​​ ​typedef​ ​struct​ ​dato{
​ ​ ​ ​int​ ​codigo;
​ ​ ​ ​int​ ​cantidad;
​ ​ ​ ​ ​ ​ ​}dato_t;
La función debe devolver -1 en caso que haya un error en el pedido de memoria o 0 si el
dato​ ​fue​ ​insertado​ ​con​ ​éxito.

alumno: cristian fragale
 */

#include "cristian.h"

int main (void)
{
		nodo_t* ptrH=NULL;
		dato_t dt;
        while(1)
        {
			printf("ingrese el codigo \n");
			scanf("%d",&dt.codigo);
			printf("ingrese la cantidad \n");
			scanf("%d",&dt.cantidad);
			insert(&ptrH,dt);
			
		}
		return 0;
} 


 
