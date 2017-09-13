/*
3. Realice una función que reciba un vector de strings ​ , ​ identifique cuales de esos strings solo
contienen caracateres numéricos (es aconsejable hacer una función aparte que haga el
análisis del string para informar si son todos caracteres numéricos). De todos los string que
solo posean caracteros numéricos calcule la suma y devuelva dicho valor.
Su prototipo será:​ 

					int sumador( char ** vector, int tam );

Para probar la función utilice los argumentos del main como vector de strings.
*/
#include "parcial.h"
int main(int argc, char *argv[])
{
	int suma=0;
	if (argv[1]==NULL){
		printf("no hay argumentos\n");
		return 0;
	}
	suma=sumador(argv, argc);
	printf("la suma es: %d\n", suma);
	return 0;
}