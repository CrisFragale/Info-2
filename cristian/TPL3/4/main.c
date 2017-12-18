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