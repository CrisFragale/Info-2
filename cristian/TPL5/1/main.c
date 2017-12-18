#include "cristian.h"

int main (void)
{  

  int error; 
  char buff[40]; 
  nodo_t *h=NULL; 
  printf("ingrese el nombre del archivo \n"); 
  scanf("%s",buff); 
  error=lecturaPacientes (&h,buff); 
  printf("el error fue %d",error); 
  imprimir(h); 
  return 0;
} 