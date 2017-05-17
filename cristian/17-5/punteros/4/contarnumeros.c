#include"contar.h"

void contadorDeNumeros (int* p)
{   int a;
    do{
        printf("ingrese un numero, o 0 para salir\n");
        scanf("%d",&a);
        if(a>0)*p=*p+1;
        
      }while(a!=0);
}      
