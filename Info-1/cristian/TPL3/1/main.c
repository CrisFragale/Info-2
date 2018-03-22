/* Realice una función que reciba como parámetro la dirección de comienzo de dos strings y
retorne 1 si ambas cadenas son iguales y 0 si no lo son.
Su prototipo será:​ int my_strEqu( char * str1, char * str2) */
 
#include "cristian.h"

int main (void)
{
	int validacion=0;
	char str1[CADENA];
	char str2[CADENA];
	fgets(str1,CADENA,stdin);
	fgets(str2,CADENA,stdin);
    validacion=my_strEqu(str1,str2);
    if(validacion==1)
    {
    	printf("son iguales\n");
    }else{
    	printf("son diferentes\n");
    }
    return 0;
} 