#include "str.h"
int main(){
	char vec1[TAM];
	char vec2[TAM];
	int a=0;
	printf("ingrese la frase\n");
	fgets(vec1, TAM, stdin);
	__fpurge(stdin);
	printf("ingrese la palabra que quiere buscar\n");
	scanf("%s", vec2);
	a = my_strcmp (vec1, vec2);
	if(a==1){
		printf("se encontró la palabra %s\n", vec2);
	}
	else{
		printf("no se encontró la palabra %s\n", vec2);
	}
	return 0;
}