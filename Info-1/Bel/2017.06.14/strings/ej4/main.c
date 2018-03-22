#include "str.h"
int encuentro (char *, char *);
int main(){
	char vec1[TAM];
	char vec2[TAM];
	int a=0;
	printf("ingrese la frase\n");
	fgets(vec1, TAM, stdin);
	__fpurge(stdin);
	printf("ingrese la palabra que quiere buscar\n");
	scanf("%s", vec2);
	a = encuentro (vec1, vec2);
	printf("%d\n", a);
	return 0;
}