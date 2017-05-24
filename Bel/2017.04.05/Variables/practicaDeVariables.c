#include <stdio.h>
int main(){
	float endente;
	float erno=0;
	float ernado;
	int lala;
	int lele;
	printf("ingrese operando 1\n");
	scanf("%f", &endente);
	//while (erno==0){
		printf("ingrese operando 2\n");
		scanf("%f", &erno);
	//}
	lala=endente;
	lele=erno;
	if(erno!=0){
		ernado = endente + erno;
		printf("el resultado es: %d\n", (int)ernado );
		ernado = endente - erno;
		printf("el resultado es: %d\n", (int)ernado );
		ernado = endente * erno;
		printf("el resultado es: %d\n", (int)ernado );
		ernado = endente / erno;
		printf("el resultado es: %f\n", ernado );
		ernado = lala % lele;
		printf("el resultado es: %d\n", (int)ernado );
	}
	else{
		printf("0 no es un valor valido para el segundo operando.\n");
	}
	printf("ingrese operando 2\n");
	scanf("%f", &erno);
	if (erno==0){
		while (erno==0){
			printf("imbecil, cualquier numero menos 0.\n");
			scanf("%f", &erno);
		}
	}
	ernado = endente + erno;
		printf("el resultado es: %d\n", (int)ernado );
		ernado = endente - erno;
		printf("el resultado es: %d\n", (int)ernado );
		ernado = endente * erno;
		printf("el resultado es: %d\n", (int)ernado );
		ernado = endente / erno;
		printf("el resultado es: %f\n", ernado );
		ernado = lala % lele;
		printf("el resultado es: %d\n", (int)ernado );
	return 0;
}