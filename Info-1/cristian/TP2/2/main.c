/*
 Implementar una función que reciba un número que representa una cantidad de segundos y
devuelva su equivalente en horas, minutos y segundos. El resultado de lo calculado se
deberá pasar por referencia, la función debe retornar void.
 
*/
 
#include "cristian.h"

int main (void)
{
   float segundos;
    int horas=0,minutos=0,segundos2=0;
    scanf("%f",&segundos);
    convertidor(segundos,&horas,&minutos,&segundos2);
    printf("la conversion fue \n %d horas \n %d minutos\n %d segundos\n ",horas,minutos,segundos2);
    return(0);
    
    
}