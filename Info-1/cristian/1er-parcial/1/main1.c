 /*Realice una función que invierta una cadena de caracteres. ​Por ejemplo: si me llega la
cadena “informática1” se deberá devolver “1acitámrofni”​. A su vez me deberá informar si la
cadena es capicúa.
Su prototipo será:​ int strInvertir( char * str );
La función deberá devolver:
● -1 si el puntero es NULL.
● 0 si se invirtió la cadena y la misma NO ES capicúa.
● 1 si se invirtió la cadena y ES capicúa. */

#include "cristian.h"

int main (void)
{
	char str[TAM];
	int informacion;
	fgets (str,TAM, stdin);
    informacion= strInvertir (str);
    printf("%d\n",informacion);
    if(informacion==1)
    {
    	printf("es un palindromo \n");
    }
    printf("invertido quedo : %s\n",str);
    return 0;


} 
