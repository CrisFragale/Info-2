 #include"cristian.h"

int main (void)
{
	int verificacion;
	char frase[TAM];
	char palabra[PAL];
	printf("ingrese la frase luego la palabra \n"); 
	fgets(frase,TAM,stdin);
	scanf("%s",palabra);
    verificacion=verificacion2(frase,palabra);
    printf("%d \n",verificacion);
    return (0);
}