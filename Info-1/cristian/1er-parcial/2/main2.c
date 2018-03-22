/*
Realizar una función que reciba un string y analice el contenido del mismo buscando la
palabra ​“suma” (la misma no se encuentra necesariamente desde la posición . En caso que
la palabra se encuentre ​luego de ella se deberá encontrar dos puntos (‘:’) y luego de los dos
puntos un número (este número solo posee parte entera y es positivo). La función debe
extraer dicho número y devolverlo en formato entero.
Su prototipo será:​ int extraerNumero( char * str );
La función deberá devolver:
● -1 si no se encuentra la palabra “suma”.
● El número si se encuentra la palabra “suma”.*/


#include "cristian.h" 
 int main (void)
{
	char str[TAM];
	int informacion;

	fgets (str,TAM, stdin);
	informacion=extraerNumero(str);
	if(informacion==-1)
	{
		printf("no se encontro la palabra suma:\n");
		return 0;
	}
	printf("el numero era %d \n",informacion);
	return 0;
} 