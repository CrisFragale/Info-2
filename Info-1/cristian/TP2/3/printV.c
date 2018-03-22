#include"cristian.h"

void printVector (int* v, int tam)
{
    while (tam>0)
    {    
         
         printf("%d\n",v[tam-1]);
         tam--;
    }
    return;
}