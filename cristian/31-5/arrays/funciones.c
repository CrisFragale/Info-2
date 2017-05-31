#include"cristian.h"

void cargarvector (int* vector, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
       scanf("%d",&vector[i]); 
    }
    return;
}

void mostrarvector (int* vector, int tam)
{
    int i;
    printf("voy a mostrar el vector \n");
    for(i=0;i<tam;i++)
    {
       printf("%d\n",vector[i]); 
    }
    return; 
}

float promedio (int* vector, int tam)
{
    int i;
    float prom=0;
    for(i=0;i<tam;i++)
    {
       prom=prom + vector[i]; 
    }
    prom=prom/tam;
    return (prom);
}