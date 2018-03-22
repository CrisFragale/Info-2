/*
1. Realice una función que invierta una cadena de caracteres. ​ Por ejemplo: si me llega la
cadena “informática1” se deberá devolver “1acitámrofni” ​ . A su vez me deberá informar si la
cadena es capicúa.
Su prototipo será:​ 

						int strInvertir( char * str );

La función deberá devolver:
● -1 si el puntero es NULL.
● 0 si se invirtió la cadena y la misma NO ES capicúa.
● 1 si se invirtió la cadena y ES capicúa.
*/
#include "parcial.h"
int main(){
	char palabra [TAM];
	int respuesta;
	printf("ingrese una palabra\n");
	scanf("%s", palabra);
	respuesta = strInvertir( palabra );
	switch(respuesta){
		case 0:
			printf("la palabra no es capicúa\n");	
			printf("su palabra invertida es: %s\n", palabra);
		break;
		case 1:
			printf("la palabra es capicúa\n");
			printf("su palabra invertida es: %s\n", palabra);
		break;
		case -1:
			printf("no ingresó nada.\n");
	}
	return 0;
}