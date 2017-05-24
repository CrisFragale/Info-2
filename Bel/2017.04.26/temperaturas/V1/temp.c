#include <stdio.h>
#define VALOR 10
int main(){
	int suma=0, tempmax=0, tempmin=0, temp=0, i;
	float prom;
	for(i=0; i<VALOR; i++){
		printf("ingrese una temperatura\n");
		scanf("%d", &temp);
		if (temp==0){
			return 0;
		}
		suma+=temp;
		if (tempmax<temp){
			tempmax=temp;
		}
		if (tempmin>temp){
			tempmin=temp;
		}
	}
	prom=(float)suma/VALOR;
	printf("el promedio de las temperaturas es:%f, la temperatura maxima es:%d, la temperatura minima es:%d \n",prom , tempmax, tempmin);
	return 0;
}