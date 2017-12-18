/*
Realice una función que realice la búsqueda de una palabra en una oración y la remplace por
***** (del largo de la palabra buscada). Debe reemplazar todas las ocurrencias de la palabra
buscada y devolver la cantidad de veces encontrada.
El prototipo es: ​int ocultarPalabra( char * oracion, char * palabra)
Nota:​ Se recomienda el uso de la función strstr para realizar este ejercicio.

*/ 
#include "cristian.h"

int main (void)
{  
  char oracion[CADENA];
  char palabra[TAM];
  int found;
  printf("ingrese la oracion\n");
  fgets (oracion, CADENA, stdin);
  printf("ingrese la palabra a buscar\n");
  scanf("%s",palabra);
  found=ocultarPalabra(oracion,palabra);
  printf("encontro %d veces la palabra\n",found);
  printf("la oracion quedo:\n %s",oracion);
  return 0;
}