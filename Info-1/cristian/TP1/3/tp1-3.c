/*
Cristian fragale 
Escriba un programa para calcular la resistencia total de un circuito en paralelo. En tal
circuito la resistencia total es la inversa de la suma de las inversas de todos los valores
individuales de las resistencias.
Suponer que el circuito consiste en una cantidad de 20 resistores ingresados por el usuario.
Si el usuario ingresa un valor negativo o el valor 0 se debe ignorar el valor, mostrar un
mensaje de “valor incorrecto”, y volver a pedir otro valor. (Recordar Rtotal = 1/[1/R1 + 1/R2
+ 1/R3 + ... + 1/Rn]). El resultado deberá aparecer con dos decimales.

*/
#include<stdio.h>

int main (void)
{
    int i=0;
    float suma=0, RT=0,R;
    printf("ingrese el valor de 20 resistencias\n");
    for(i=0;i<20;i++)
	{
	   R=-1; 
	   while(R<=0)
	   {
			scanf("%f",&R);
			if (R<=0) { 
				// no es necesario { } cuando es una sola línea, pero es
				// super recomendado. 				
				printf("valor incorrecto, ingrese otro valor\n");
			}
	   }
	 suma=(suma+((1/R)));
	}
    RT=(1/suma);
    printf("La resistencia total es: %.2f",RT);
    return(0);
}
