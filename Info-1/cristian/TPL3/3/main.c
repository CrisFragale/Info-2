/*
  
  Haciendo uso de la ​función del punto 2 implemente un programa que oculte todas las
palabras ingresadas por línea de comando de una frase ingresada por el usuario. Finalmente
se deberá mostrar por pantalla la frase con todas las palabras ocultas.

  
*/ 

#include "cristian.h"

int main (int argc, char **argv)
{
  char oracion[CADENA];
  int found,i,totally=0;
  printf("ingrese la oracion\n");
  fgets (oracion, CADENA, stdin);
 
  for (i=(argc-1);i>0;i--)
  {
  		found=ocultarPalabra(oracion,argv[i]);
        totally+=found;
  }
  
  printf("encontraron %d veces las palabras en total\n",totally);
  printf("la oracion quedo:\n %s",oracion);
  return 0;
}