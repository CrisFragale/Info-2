/*
Cristian fragale
Escriba un programa donde ingresa una serie de números enteros y positivos e informe cuál
es par y cual es impar. En caso que el número sea negativo se debe informar “número
incorrecto” y pedir otro número. El fin del ingreso se da al recibir un 0 que no pertenece a la
serie. Al finalizar deberá informar cuántos son par y cuantos impar.
*/

#include<stdio.h>

int main (void)
{
    int numero=0, pares=0, impares=0,k;
    printf("ingrese numeros, este ingreso finalzara al ingresar un 0\n");
    scanf("%d",&numero);
    while (numero!=0)
	{
		if(numero<0)
		{ 
			printf("Numero incorrecto\n");
        
		}
		else
		{
			k=(numero%2);
			if(k!=0)
            {
				impares++;  
            }
            else 
            {
				pares++;   
            }   
		}
		printf("ingrese otro numero o 0 para finalizar\n"); 
		scanf("%d",&numero); 
	}
    printf("los numeros ingresados fueron:\n pares %d \n impares %d\n",pares,impares);    
    return(0);
}
