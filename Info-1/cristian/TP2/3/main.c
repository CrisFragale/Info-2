/*
 * Realizar una función que imprima el contenido de un vector de enteros de forma inversa
(desde la última posición a la primera) el prototipo de la función deberá ser:
void printVector(int * v, int tam);

 */
#include"cristian.h"


int main (void)
{
    
    int v[TAM];
    int i=0;
    for(i=0;i<TAM;i++)
    {
         v[i]=i+4;
    }
    printVector(v, TAM);
    return(0);
}