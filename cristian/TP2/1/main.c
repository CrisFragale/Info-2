/*
 Implemente una función la cual modifique el carácter recibido como parámetro para
convertir una letra a mayúscula.
El prototipo es​ ​int aMayuscula (char * caracter);
La función deberá devolver
●
 0: si el caracter es una letra .
●
 -1: si el caracter no es una letra.


*/
#include"cristian.h"

int main (void)
{
    char caracter,validacion;
    scanf("%c",&caracter);
    validacion=aMayuscula(&caracter);
    if (validacion==-1)
    {
        printf("El caracter no es una letra\n");
        return 0;
    }
    printf("El resultado se la conversion fue: %c\n",caracter);    
    return 0;
}
