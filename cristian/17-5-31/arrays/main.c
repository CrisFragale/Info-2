#include"cristian.h"

int main (void)
{
    int vector[TAM];
    float result;
    cargarvector(vector,TAM);
    mostrarvector(vector,TAM);
    result=promedio(vector,TAM);
    printf("el promedio fue: %.2f\n",result);
    return (0);
    
}