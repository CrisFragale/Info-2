/*
2. Realizar una función que reciba un string y analice el contenido del mismo buscando la
palabra ​ “suma” (la misma no se encuentra necesariamente desde la posición . En caso que
la palabra se encuentre ​ luego de ella se deberá encontrar dos puntos (‘:’) y luego de los dos
puntos un número (este número solo posee parte entera y es positivo). La función debe
extraer dicho número y devolverlo en formato entero.
Su prototipo será:​ 

							int extraerNumero( char * str );

La función deberá devolver:
● -1 si no se encuentra la palabra “suma”.
● El número si se encuentra la palabra “suma”.
*/
#include "parcial.h"
int main(){
	char palabra[TAM];
	int result=0;
	printf("ingrese una palabra. finalice con : y un numero positivo.\n para ver su numero debe poner en el string la palabra suma.\n");
	scanf("%s", palabra);
	result = extraerNumero(palabra);
	if (result == -1){
		printf("no ingresó la palabra suma.\n");
	}
	else{
		printf("%d\n", result);
	}
	return 0;
}