#include"contar.h" 

int main (void)
{
    int cantidad=0;
    contadorDeNumeros(&cantidad);
    printf("la cantidad de numeros positivos fueron %d\n",cantidad);
    return(0);
}