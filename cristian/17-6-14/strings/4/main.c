 
 #include"cristian.h"

int main (void)
{    
	int encontradas;
	char frase[TAM];
	char palabra[PAL];
	printf("ingrese la frase luego la palabra \n"); 
	fgets(frase,TAM,stdin);
	scanf("%s",palabra);
    encontradas=encontrar(frase,palabra);
    printf("%d \n",encontradas);
    return(0);
}